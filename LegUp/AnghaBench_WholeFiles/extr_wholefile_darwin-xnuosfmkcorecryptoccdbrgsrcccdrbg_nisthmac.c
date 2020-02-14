#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ uint64_t ;
struct ccdrbg_state {int dummy; } ;
struct ccdrbg_nisthmac_state {size_t keysize; size_t vsize; void const* vptr; size_t bytesLeft; void const* nextvptr; int reseed_counter; void const* v; int /*<<< orphan*/  key; struct ccdrbg_nisthmac_custom const* custom; } ;
typedef  struct ccdrbg_nisthmac_custom {struct ccdigest_info* di; } const ccdrbg_nisthmac_custom ;
struct ccdrbg_info {int size; int (* init ) (struct ccdrbg_info const*,struct ccdrbg_state*,size_t,void const*,size_t,void const*,size_t,void const*) ;int (* generate ) (struct ccdrbg_state*,size_t,void*,size_t,void const*) ;int (* reseed ) (struct ccdrbg_state*,size_t,void const*,size_t,void const*) ;void (* done ) (struct ccdrbg_state*) ;struct ccdrbg_nisthmac_custom const* custom; } ;
struct ccdigest_info {int output_size; int /*<<< orphan*/  block_size; int /*<<< orphan*/  state_size; } ;

/* Variables and functions */
 size_t CCDRBG_MAX_ADDITIONALINPUT_SIZE ; 
 size_t CCDRBG_MAX_ENTROPY_SIZE ; 
 size_t CCDRBG_MAX_PSINPUT_SIZE ; 
 size_t CCDRBG_MAX_REQUEST_SIZE ; 
 scalar_t__ CCDRBG_RESEED_INTERVAL ; 
 int CCDRBG_STATUS_ABORT ; 
 int CCDRBG_STATUS_ERROR ; 
 int CCDRBG_STATUS_NEED_RESEED ; 
 int CCDRBG_STATUS_OK ; 
 int CCDRBG_STATUS_PARAM_ERROR ; 
 int /*<<< orphan*/  CC_MEMCPY (char*,void const*,size_t) ; 
 int /*<<< orphan*/  CC_MEMSET (void const*,int,size_t) ; 
 int /*<<< orphan*/  CC_SWAP (void const*,void const*) ; 
 size_t MIN_REQ_ENTROPY (struct ccdigest_info const*) ; 
 int NH_MAX_OUTPUT_BLOCK_SIZE ; 
 int /*<<< orphan*/  cc_clear (int,struct ccdrbg_nisthmac_state*) ; 
 scalar_t__ cc_cmp_safe (size_t,void const*,void const*) ; 
 int /*<<< orphan*/  cc_require (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cc_try_abort (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cc_zero (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cchmac (struct ccdigest_info const*,size_t,int /*<<< orphan*/ ,size_t,void const*,void const*) ; 
 int /*<<< orphan*/  cchmac_ctx_decl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cchmac_final (struct ccdigest_info const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cchmac_init (struct ccdigest_info const*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cchmac_update (struct ccdigest_info const*,int /*<<< orphan*/ ,size_t,void const*) ; 
 int /*<<< orphan*/  ctx ; 
static  void done (struct ccdrbg_state*) ; 
 int /*<<< orphan*/  end ; 

__attribute__((used)) static int hmac_dbrg_update(struct ccdrbg_state *drbg,
                            size_t daLen, const void *da,
                            size_t dbLen, const void *db,
                            size_t dcLen, const void *dc
                            )
{
    int rc=CCDRBG_STATUS_ERROR;
    struct ccdrbg_nisthmac_state *state = (struct ccdrbg_nisthmac_state *)drbg;
    const struct ccdigest_info *di = state->custom->di;

    const unsigned char cZero = 0x00;
    const unsigned char cOne  = 0x01;

    cchmac_ctx_decl(di->state_size, di->block_size, ctx);
    cchmac_init(di, ctx, state->keysize, state->key);

    // 1. K = HMAC (K, V || 0x00 || provided_data).
    cchmac_update(di, ctx, state->vsize, state->vptr);
    cchmac_update(di, ctx, 1, &cZero);
    if (da && daLen) cchmac_update(di, ctx, daLen, da);
    if (db && dbLen) cchmac_update(di, ctx, dbLen, db);
    if (dc && dcLen) cchmac_update(di, ctx, dcLen, dc);
    cchmac_final(di, ctx, state->key);

    // One parameter must be non-empty, or return
    if (((da && daLen) || (db && dbLen) || (dc && dcLen))) {
        //  2. V=HMAC(K,V).
        cchmac(di, state->keysize, state->key, state->vsize, state->vptr, state->vptr);
        //  4. K = HMAC (K, V || 0x01 || provided_data).
        cchmac_init(di, ctx, state->keysize, state->key);
        cchmac_update(di, ctx, state->vsize, state->vptr);
        cchmac_update(di, ctx, 1, &cOne);
        if (da && daLen) cchmac_update(di, ctx, daLen, da);
        if (db && dbLen) cchmac_update(di, ctx, dbLen, db);
        if (dc && dcLen) cchmac_update(di, ctx, dcLen, dc);
        cchmac_final(di, ctx, state->key);
    }
    //  If additional data 5. V=HMAC(K,V)
    //  If no addtional data, this is step 2. V=HMAC(K,V).
    state->bytesLeft = 0;

    // FIPS 140-2 4.9.2 Conditional Tests
    // "the first n-bit block generated after power-up, initialization, or reset shall not be used, but shall be saved for comparison with the next n-bit block to be generated"
    // Generate the first block and the second block. Compare for FIPS and discard the first block
    // We keep the second block as the first set of data to be returned
    cchmac(di, state->keysize, state->key, state->vsize, state->vptr, state->vptr);     // First block
    cchmac(di, state->keysize, state->key, state->vsize, state->vptr, state->nextvptr); // First to be returned
    if (0==cc_cmp_safe(state->vsize, state->vptr, state->nextvptr)) {
        //The world as we know it has come to an end
        //the DRBG data structure is zeroized. subsequent calls to
        //DRBG ends up in NULL dereferencing and/or unpredictable state.
        //catastrophic error in SP 800-90A
        done(drbg);
        rc=CCDRBG_STATUS_ABORT;
        cc_try_abort(NULL);
        goto errOut;
    }
    rc=CCDRBG_STATUS_OK;
errOut:
    return rc;
}

__attribute__((used)) static int validate_inputs(struct ccdrbg_nisthmac_state *state,
                           size_t entropyLength,
                           size_t additionalInputLength,
                           size_t psLength)
{
    int rc;
    const struct ccdrbg_nisthmac_custom *custom=state->custom;
    const struct ccdigest_info *di  = custom->di;

    rc =CCDRBG_STATUS_ERROR;
    //buffer size checks
    cc_require (di->output_size<=sizeof(state->v)/2, end); //digest size too long
    cc_require (di->output_size<=sizeof(state->key), end); //digest size too long

    //NIST SP800 compliance checks
    //the following maximum checks are redundant if long is 32 bits.

    rc=CCDRBG_STATUS_PARAM_ERROR;
    cc_require (psLength <= CCDRBG_MAX_PSINPUT_SIZE, end); //personalization string too long
    cc_require (entropyLength <= CCDRBG_MAX_ENTROPY_SIZE, end); //supplied too much entropy
    cc_require (additionalInputLength <= CCDRBG_MAX_ADDITIONALINPUT_SIZE, end); //additional input too long
    cc_require (entropyLength >=  MIN_REQ_ENTROPY(di), end); //supplied too litle entropy

    cc_require(di->output_size<=NH_MAX_OUTPUT_BLOCK_SIZE, end); //the requested security strength is not supported

    rc=CCDRBG_STATUS_OK;
end:
    return rc;
}

__attribute__((used)) static int hmac_dbrg_instantiate_algorithm(struct ccdrbg_state *drbg,
                                           size_t entropyLength, const void *entropy,
                                           size_t nonceLength, const void *nonce,
                                           size_t psLength, const void *ps)
{
    // TODO: The NIST code passes nonce (i.e. HMAC key) to generate, but cc interface isn't set up that way
    struct ccdrbg_nisthmac_state *state = (struct ccdrbg_nisthmac_state *)drbg;

    // 1. seed_material = entropy_input || nonce || personalization_string.

    // 2. Set Key to outlen bits of zeros.
    cc_zero(state->keysize, state->key);

    // 3. Set V to outlen/8 bytes of 0x01.
    CC_MEMSET(state->vptr, 0x01, state->vsize);

    // 4. (Key, V) = HMAC_DRBG_Update (seed_material, Key, V).
    hmac_dbrg_update(drbg, entropyLength, entropy, nonceLength, nonce, psLength, ps);

    // 5. reseed_counter = 1.
    state->reseed_counter = 1;

    return CCDRBG_STATUS_OK;
}

__attribute__((used)) static int init(const struct ccdrbg_info *info, struct ccdrbg_state *drbg,
                size_t entropyLength, const void* entropy,
                size_t nonceLength, const void* nonce,
                size_t psLength, const void* ps)
{
    struct ccdrbg_nisthmac_state *state=(struct ccdrbg_nisthmac_state *)drbg;
    state->bytesLeft = 0;
    state->custom = info->custom; //we only need to get the custom parameter from the info structure.

    int rc = validate_inputs(state , entropyLength, 0, psLength);
    if(rc!=CCDRBG_STATUS_OK){
        //clear everything if cannot initialize. The idea is that if the caller doesn't check the output of init() and init() fails,
        //the system crashes by NULL dereferencing after a call to generate, rather than generating bad random numbers.
        done(drbg);
        return rc;
    }

    const struct ccdigest_info *di = state->custom->di;
    state->vsize = di->output_size;
    state->keysize = di->output_size;
    state->vptr=state->v;
    state->nextvptr=state->v+state->vsize;

    // 7. (V, Key, reseed_counter) = HMAC_DRBG_Instantiate_algorithm (entropy_input, personalization_string).
    hmac_dbrg_instantiate_algorithm(drbg, entropyLength, entropy, nonceLength, nonce, psLength, ps);

#if DRBG_NISTHMAC_DEBUG
    dumpState("Init: ", state);
#endif
    return CCDRBG_STATUS_OK;

}

__attribute__((used)) static int
reseed(struct ccdrbg_state *drbg,
       size_t entropyLength, const void *entropy,
       size_t additionalLength, const void *additional)
{

    struct ccdrbg_nisthmac_state *state = (struct ccdrbg_nisthmac_state *)drbg;
    int rc = validate_inputs(state, entropyLength, additionalLength, 0);
    if(rc!=CCDRBG_STATUS_OK) return rc;

    int rx = hmac_dbrg_update(drbg, entropyLength, entropy, additionalLength, additional, 0, NULL);
    state->reseed_counter = 1;

#if DRBG_NISTHMAC_DEBUG
    dumpState("Reseed: ", state);
#endif
    return rx;
}

__attribute__((used)) static int validate_gen_params(uint64_t reseed_counter,  size_t dataOutLength, size_t additionalLength)

{
    int rc=CCDRBG_STATUS_PARAM_ERROR;

    // Zero byte in one request is a valid use-case (21208820)
    cc_require (dataOutLength <= CCDRBG_MAX_REQUEST_SIZE, end); //Requested too many bytes in one request
    cc_require (additionalLength<=CCDRBG_MAX_ADDITIONALINPUT_SIZE, end); //Additional input too long

    // 1. If (reseed_counter > 2^^48), then Return (“Reseed required”, Null, V, Key, reseed_counter).
     rc = CCDRBG_STATUS_NEED_RESEED;
     cc_require (reseed_counter <= CCDRBG_RESEED_INTERVAL, end); //Reseed required

    rc=CCDRBG_STATUS_OK;

end:
    return rc;
}

__attribute__((used)) static int generate(struct ccdrbg_state *drbg, size_t dataOutLength, void *dataOut,
                    size_t additionalLength, const void *additional)
{
    struct ccdrbg_nisthmac_state *state = (struct ccdrbg_nisthmac_state *)drbg;
    const struct ccdrbg_nisthmac_custom *custom = state->custom;
    const struct ccdigest_info *di = custom->di;

    int rc = validate_gen_params(state->reseed_counter, dataOutLength, additional==NULL?0:additionalLength);
    if(rc!=CCDRBG_STATUS_OK) return rc;

    // 2. If additional_input ≠ Null, then (Key, V) = HMAC_DRBG_Update (additional_input, Key, V).
    if (additional && additionalLength)
        hmac_dbrg_update(drbg, additionalLength, additional, 0, NULL, 0, NULL);

    // hmac_dbrg_generate_algorithm
    char *outPtr = (char *) dataOut;
    while (dataOutLength > 0) {
        if (!state->bytesLeft) {
            //  5. V=HMAC(K,V).
            cchmac(di, state->keysize, state->key, state->vsize, state->nextvptr, state->vptr);        // Won't be returned
            // FIPS 140-2 4.9.2 Conditional Tests
            // "Each subsequent generation of an n-bit block shall be compared with the previously generated block. The test shall fail if any two compared n-bit blocks are equal."
            if (0==cc_cmp_safe(state->vsize, state->vptr, state->nextvptr)) {
                //The world as we know it has come to an end
                //the DRBG data structure is zeroized. subsequent calls to
                //DRBG ends up in NULL dereferencing and/or unpredictable state.
                //catastrophic error in SP 800-90A
                done(drbg);
                rc=CCDRBG_STATUS_ABORT;
                cc_try_abort(NULL);
                goto errOut;
            }
            CC_SWAP(state->nextvptr, state->vptr);
            state->bytesLeft = state->vsize;
#if DRBG_NISTHMAC_DEBUG
            cc_print("generate blk: ", state->vsize, state->vptr);
#endif
        }
        size_t outLength = dataOutLength > state->bytesLeft ? state->bytesLeft : dataOutLength;
        CC_MEMCPY(outPtr, state->vptr, outLength);
        state->bytesLeft -= outLength;
        outPtr += outLength;
        dataOutLength -= outLength;
    }

    // 6. (Key, V) = HMAC_DRBG_Update (additional_input, Key, V).
    hmac_dbrg_update(drbg, additionalLength, additional, 0, NULL, 0, NULL);

    // 7. reseed_counter = reseed_counter + 1.
    state->reseed_counter++;

#if DRBG_NISTHMAC_DEBUG
    dumpState("generate end: ", state);
    cc_print("generate end nxt: ", state->vsize, state->nextvptr);
#endif
    rc=CCDRBG_STATUS_OK;
errOut:
    return rc;
}

__attribute__((used)) static void done(struct ccdrbg_state *drbg)
{
    struct ccdrbg_nisthmac_state *state=(struct ccdrbg_nisthmac_state *)drbg;
    cc_clear(sizeof(struct ccdrbg_nisthmac_state), state); //clear v, key as well as internal variables
}

void ccdrbg_factory_nisthmac(struct ccdrbg_info *info, const struct ccdrbg_nisthmac_custom *custom)
{
    info->size = sizeof(struct ccdrbg_nisthmac_state) + sizeof(struct ccdrbg_nisthmac_custom);
    info->init = init;
    info->generate = generate;
    info->reseed = reseed;
    info->done = done;
    info->custom = custom;
}

