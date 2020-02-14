#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_106__   TYPE_97__ ;
typedef  struct TYPE_105__   TYPE_90__ ;
typedef  struct TYPE_104__   TYPE_5__ ;
typedef  struct TYPE_103__   TYPE_4__ ;
typedef  struct TYPE_102__   TYPE_3__ ;
typedef  struct TYPE_101__   TYPE_2__ ;
typedef  struct TYPE_100__   TYPE_20__ ;
typedef  struct TYPE_99__   TYPE_1__ ;

/* Type definitions */
struct TYPE_103__ {int /*<<< orphan*/  mf; } ;
struct TYPE_104__ {size_t operation; TYPE_4__ number; } ;
struct TYPE_102__ {struct TYPE_102__* next; TYPE_5__ node; } ;
typedef  TYPE_3__ stack_node_t ;
typedef  int /*<<< orphan*/  mpz_t ;
typedef  int /*<<< orphan*/  mpfr_t ;
typedef  int /*<<< orphan*/  (* exec_call_t ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;
typedef  TYPE_4__ calc_number_t ;
typedef  TYPE_5__ calc_node_t ;
struct TYPE_100__ {int /*<<< orphan*/  mf; } ;
struct TYPE_101__ {TYPE_20__ number; } ;
struct TYPE_99__ {int /*<<< orphan*/  mf; } ;
struct TYPE_106__ {scalar_t__ base; unsigned int prev_operator; unsigned int last_operator; TYPE_2__ memory; TYPE_4__ prev; TYPE_1__ code; void* is_nan; scalar_t__ sci_in; } ;
struct TYPE_105__ {unsigned int prec; int /*<<< orphan*/  (* op_i ) (TYPE_4__*,TYPE_4__*,TYPE_4__*) ;int /*<<< orphan*/  (* op_f ) (TYPE_4__*,TYPE_4__*,TYPE_4__*) ;int /*<<< orphan*/  (* op_p ) (TYPE_4__*,TYPE_4__*,TYPE_4__*) ;} ;

/* Variables and functions */
 void* FALSE ; 
 scalar_t__ IDC_RADIO_DEC ; 
 int /*<<< orphan*/  MPFR_DEFAULT_RND ; 
 unsigned int RPN_OPERATOR_EQUAL ; 
 unsigned int RPN_OPERATOR_NONE ; 
 unsigned int RPN_OPERATOR_PARENT ; 
 unsigned int RPN_OPERATOR_PERCENT ; 
 void* TRUE ; 
 int /*<<< orphan*/  apply_int_mask (TYPE_4__*) ; 
 TYPE_97__ calc ; 
 void flush_postfix () ; 
 int /*<<< orphan*/  free (TYPE_3__*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  mpf_set_default_prec (int) ; 
 int /*<<< orphan*/  mpfr_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_add_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_div (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_div_2exp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_div_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ mpfr_fits_ulong_p (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long mpfr_get_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_get_z (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_init_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_mul (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_mul_2exp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_mul_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_pow (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_set_default_prec (int) ; 
 int /*<<< orphan*/  mpfr_set_z (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mpfr_sgn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sub (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_sub_ui (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_trunc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpfr_ui_div (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_and (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_ior (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_mul (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_sub (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_tdiv_q (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_tdiv_r (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpz_xor (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_90__* operator_list ; 
 void* percent_mode ; 
 int /*<<< orphan*/  rpn_alloc (TYPE_4__*) ; 
 int /*<<< orphan*/  rpn_copy (TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  rpn_free (TYPE_4__*) ; 
 int /*<<< orphan*/  rpn_zero (TYPE_20__*) ; 
 TYPE_3__* stack ; 
 int /*<<< orphan*/  stub1 (TYPE_4__*,TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_4__*,TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_4__*,TYPE_4__*,TYPE_4__*) ; 
 TYPE_5__ temp ; 

__attribute__((used)) static void node_copy(calc_node_t *dst, calc_node_t *src)
{
    mpfr_set(dst->number.mf, src->number.mf, MPFR_DEFAULT_RND);
    dst->operation = src->operation;
}

__attribute__((used)) static calc_node_t *pop(void)
{
    void *next;

    if (stack == NULL)
        return NULL;

    /* copy the node */
    node_copy(&temp, &stack->node);
    next = stack->next;

    /* free the node */
    mpfr_clear(stack->node.number.mf);
    free(stack);
    stack = next;

    return &temp;
}

__attribute__((used)) static int is_stack_empty(void)
{
    return (stack == NULL);
}

__attribute__((used)) static void push(calc_node_t *op)
{
    stack_node_t *z = (stack_node_t *)malloc(sizeof(stack_node_t));

    mpfr_init_set(z->node.number.mf, op->number.mf, MPFR_DEFAULT_RND);
    z->node.operation = op->operation;
    z->next = stack;
    stack = z;
}

__attribute__((used)) static void rpn_exec_int(calc_number_t *r, calc_number_t *a, calc_number_t *b, exec_call_t cb)
{
    mpz_t ai, bi;

    mpz_init(ai);
    mpz_init(bi);
    mpfr_get_z(ai, a->mf, MPFR_DEFAULT_RND);
    mpfr_get_z(bi, b->mf, MPFR_DEFAULT_RND);
    cb(ai, ai, bi);
    mpfr_set_z(r->mf, ai, MPFR_DEFAULT_RND);
    mpz_clear(ai);
    mpz_clear(bi);
}

__attribute__((used)) static void rpn_add_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_add(r->mf, a->mf, b->mf, MPFR_DEFAULT_RND);
}

__attribute__((used)) static void rpn_sub_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_sub(r->mf, a->mf, b->mf, MPFR_DEFAULT_RND);
}

__attribute__((used)) static void rpn_mul_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_mul(r->mf, a->mf, b->mf, MPFR_DEFAULT_RND);
}

__attribute__((used)) static void rpn_div_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    if (mpfr_sgn(b->mf) == 0)
        calc.is_nan = TRUE;
    else
        mpfr_div(r->mf, a->mf, b->mf, MPFR_DEFAULT_RND);
}

__attribute__((used)) static void rpn_and_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    rpn_exec_int(r, a, b, mpz_and);
}

__attribute__((used)) static void rpn_or_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    rpn_exec_int(r, a, b, mpz_ior);
}

__attribute__((used)) static void rpn_xor_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    rpn_exec_int(r, a, b, mpz_xor);
}

__attribute__((used)) static void rpn_shl_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    unsigned long e;

    mpfr_trunc(r->mf, b->mf);
    if (mpfr_fits_ulong_p(r->mf, MPFR_DEFAULT_RND) == 0)
        calc.is_nan = TRUE;
    else {
        e = mpfr_get_ui(r->mf, MPFR_DEFAULT_RND);
        mpfr_mul_2exp(r->mf, a->mf, e, MPFR_DEFAULT_RND);
    }
}

__attribute__((used)) static void rpn_shr_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    unsigned long e;

    mpfr_trunc(r->mf, b->mf);
    if (mpfr_fits_ulong_p(r->mf, MPFR_DEFAULT_RND) == 0)
        calc.is_nan = TRUE;
    else {
        e = mpfr_get_ui(r->mf, MPFR_DEFAULT_RND);
        mpfr_div_2exp(r->mf, a->mf, e, MPFR_DEFAULT_RND);
    }
}

__attribute__((used)) static void rpn_pow_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_pow(r->mf, a->mf, b->mf, MPFR_DEFAULT_RND);
}

__attribute__((used)) static void rpn_sqr_f(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    if (mpfr_sgn(b->mf) == 0)
        calc.is_nan = TRUE;
    else {
        mpfr_t tmp;

        mpfr_init(tmp);
        mpfr_set(tmp, b->mf, MPFR_DEFAULT_RND);
        mpfr_ui_div(tmp, 1, tmp, MPFR_DEFAULT_RND);
        mpfr_pow(r->mf, a->mf, tmp, MPFR_DEFAULT_RND);
        mpfr_clear(tmp);
    }
}

__attribute__((used)) static void rpn_add_i(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    rpn_exec_int(r, a, b, mpz_add);
}

__attribute__((used)) static void rpn_sub_i(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    rpn_exec_int(r, a, b, mpz_sub);
}

__attribute__((used)) static void rpn_mul_i(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    rpn_exec_int(r, a, b, mpz_mul);
}

__attribute__((used)) static void rpn_div_i(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    if (mpfr_sgn(b->mf) == 0)
        calc.is_nan = TRUE;
    else
        rpn_exec_int(r, a, b, mpz_tdiv_q);
}

__attribute__((used)) static void rpn_mod_i(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    if (mpfr_sgn(b->mf) == 0)
        calc.is_nan = TRUE;
    else
        rpn_exec_int(r, a, b, mpz_tdiv_r);
}

__attribute__((used)) static void rpn_add_p(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_t tmp;

    mpfr_init(tmp);
    mpfr_set(tmp, b->mf, MPFR_DEFAULT_RND);
    mpfr_div_ui(tmp, tmp, 100, MPFR_DEFAULT_RND);
    mpfr_add_ui(tmp, tmp, 1, MPFR_DEFAULT_RND);
    mpfr_mul(r->mf, a->mf, tmp, MPFR_DEFAULT_RND);
    mpfr_clear(tmp);
}

__attribute__((used)) static void rpn_sub_p(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_t tmp;

    mpfr_init(tmp);
    mpfr_set(tmp, b->mf, MPFR_DEFAULT_RND);
    mpfr_div_ui(tmp, tmp, 100, MPFR_DEFAULT_RND);
    mpfr_sub_ui(tmp, tmp, 1, MPFR_DEFAULT_RND);
    mpfr_mul(r->mf, a->mf, tmp, MPFR_DEFAULT_RND);
    mpfr_clear(tmp);
}

__attribute__((used)) static void rpn_mul_p(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    mpfr_mul(r->mf, a->mf, b->mf, MPFR_DEFAULT_RND);
    mpfr_div_ui(r->mf, r->mf, 100, MPFR_DEFAULT_RND);
}

__attribute__((used)) static void rpn_div_p(calc_number_t *r, calc_number_t *a, calc_number_t *b)
{
    if (mpfr_sgn(b->mf) == 0)
        calc.is_nan = TRUE;
    else {
        mpfr_mul_ui(r->mf, a->mf, 100, MPFR_DEFAULT_RND);
        mpfr_div(r->mf, r->mf, b->mf, MPFR_DEFAULT_RND);
    }
}

void run_operator(calc_node_t *result,
                  calc_node_t *a,
                  calc_node_t *b,
                  unsigned int operation)
{
    if (calc.base == IDC_RADIO_DEC) {
        if (percent_mode) {
            percent_mode = FALSE;
            operator_list[operation].op_p(&result->number, &a->number, &b->number);
        } else
            operator_list[operation].op_f(&result->number, &a->number, &b->number);
    } else {
        operator_list[operation].op_i(&result->number, &a->number, &b->number);
        /* apply final limiter to result */
        apply_int_mask(&result->number);
    }
}

__attribute__((used)) static void evalStack(calc_number_t *number)
{
    calc_node_t *op, ip;
    unsigned int prec;

    mpfr_init(ip.number.mf);
    op = pop();
    node_copy(&ip, op);
    prec = operator_list[ip.operation].prec;
    while (!is_stack_empty()) {
        op = pop();

        if (prec <= operator_list[op->operation].prec) {
            if (op->operation == RPN_OPERATOR_PARENT) continue;

            rpn_copy(&calc.prev, &ip.number);
            run_operator(&ip, op, &ip, op->operation);
            if (calc.is_nan) {
                flush_postfix();
                mpfr_clear(ip.number.mf);
                return;
            }
        } else {
            push(op);
            break;
        }
    }

    if (ip.operation != RPN_OPERATOR_EQUAL && ip.operation != RPN_OPERATOR_PERCENT)
        push(&ip);

    calc.prev_operator = op->operation;

    rpn_copy(number, &ip.number);
    mpfr_clear(ip.number.mf);
}

int exec_infix2postfix(calc_number_t *number, unsigned int func)
{
    calc_node_t tmp;

    if (is_stack_empty() && func == RPN_OPERATOR_EQUAL) {
        /* if a number has been entered with exponential */
        /* notation, I may update it with normal mode */
        if (calc.sci_in)
            return 1;
        return 0;
    }

    if (func == RPN_OPERATOR_PERCENT)
        percent_mode = TRUE;

    mpfr_init(tmp.number.mf);
    rpn_copy(&tmp.number, number);
    tmp.operation = func;

    push(&tmp);
    mpfr_clear(tmp.number.mf);

    if (func == RPN_OPERATOR_NONE)
        return 0;

    if (func != RPN_OPERATOR_PARENT) {
        calc.last_operator = func;
        evalStack(number);
    }
    return 1;
}

void exec_change_infix(void)
{
    stack_node_t *op = stack;

    if (op == NULL)
        return;
    if (op->node.operation == RPN_OPERATOR_PARENT ||
        op->node.operation == RPN_OPERATOR_PERCENT ||
        op->node.operation == RPN_OPERATOR_EQUAL)
        return;
    /* remove the head, it will be re-inserted with new operator */
    pop();
}

void exec_closeparent(calc_number_t *number)
{
    calc_node_t *op, ip;

    rpn_alloc(&ip.number);
    rpn_copy(&ip.number, number);
    while (!is_stack_empty()) {
        op = pop();

        if (op->operation == RPN_OPERATOR_PARENT)
            break;

        run_operator(&ip, op, &ip, op->operation);
        if (calc.is_nan) {
            flush_postfix();
            return;
        }
    }
    rpn_copy(number, &ip.number);
    rpn_free(&ip.number);
}

int eval_parent_count(void)
{
    stack_node_t *s = stack;
    int           n = 0;

    while (s != NULL) {
        if (s->node.operation == RPN_OPERATOR_PARENT)
            n++;
        s = (stack_node_t *)(s->next);
    }
    return n;
}

void flush_postfix(void)
{
    while (!is_stack_empty())
        pop();
    /* clear prev and last typed operators */
    calc.prev_operator =
    calc.last_operator = 0;
}

void start_rpn_engine(void)
{
    mpf_set_default_prec(512);
    mpfr_set_default_prec(512);
    stack = NULL;
    mpfr_init(calc.code.mf);
    mpfr_init(calc.prev.mf);
    mpfr_init(calc.memory.number.mf);
    mpfr_init(temp.number.mf);
    rpn_zero(&calc.memory.number);
}

void stop_rpn_engine(void)
{
    mpfr_clear(calc.code.mf);
    mpfr_clear(calc.prev.mf);
    mpfr_clear(calc.memory.number.mf);
    mpfr_clear(temp.number.mf);
}

