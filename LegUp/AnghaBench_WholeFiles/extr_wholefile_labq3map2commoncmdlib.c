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
typedef  double time_t ;
struct stat {int st_mtime; } ;
typedef  int /*<<< orphan*/  qboolean ;
typedef  int byte ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 char const* BASEDIRNAME ; 
 unsigned short CRC_INIT_VALUE ; 
 unsigned short CRC_XOR_VALUE ; 
 scalar_t__ EEXIST ; 
 int /*<<< orphan*/  Error (char*,...) ; 
 int MEM_BLOCKSIZE ; 
 void Q_getwd (char*) ; 
 int Q_strncasecmp (char const*,char const*,int) ; 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  Sys_Printf (char*,char*) ; 
 int atol (char const*) ; 
 void* calloc (size_t,int) ; 
 int /*<<< orphan*/  com_eof ; 
 int* com_token ; 
 unsigned short* crctable ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 size_t fread (void*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (void*) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int ftell (int /*<<< orphan*/ *) ; 
 size_t fwrite (void const*,int,int,int /*<<< orphan*/ *) ; 
 char* gamedir ; 
 int /*<<< orphan*/  getcwd (char*,int) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int mkdir (char const*,int) ; 
 int myargc ; 
 char** myargv ; 
 char* qdir ; 
 int /*<<< orphan*/  qfalse ; 
 int /*<<< orphan*/  qtrue ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,char const*) ; 
 int stat (char const*,struct stat*) ; 
 int /*<<< orphan*/  strcat (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int /*<<< orphan*/  strerror (scalar_t__) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 
 int /*<<< orphan*/  time (double*) ; 
 char tolower (char) ; 
 int /*<<< orphan*/  usleep (int) ; 
 char* writedir ; 

void *safe_malloc( size_t size ){
	void *p;

	p = calloc( size, 1 );
	if ( !p ) {
		Error( "safe_malloc failed on allocation of %i bytes", size );
	}

	return p;
}

void *safe_malloc_info( size_t size, char* info ){
	void *p;

	p = calloc( size, 1 );
	if ( !p ) {
		Error( "%s: safe_malloc failed on allocation of %i bytes", info, size );
	}

	return p;
}

void ExpandWildcards( int *argc, char ***argv ){
}

void SetQdirFromPath( const char *path ){
	char temp[1024];
	const char  *c;
	const char *sep;
	int len, count;

	if ( !( path[0] == '/' || path[0] == '\\' || path[1] == ':' ) ) { // path is partial
		Q_getwd( temp );
		strcat( temp, path );
		path = temp;
	}

	// search for "quake2" in path

	len = strlen( BASEDIRNAME );
	for ( c = path + strlen( path ) - 1 ; c != path ; c-- )
	{
		int i;

		if ( !Q_strncasecmp( c, BASEDIRNAME, len ) ) {
			//
			//strncpy (qdir, path, c+len+2-path);
			// the +2 assumes a 2 or 3 following quake which is not the
			// case with a retail install
			// so we need to add up how much to the next separator
			sep = c + len;
			count = 1;
			while ( *sep && *sep != '/' && *sep != '\\' )
			{
				sep++;
				count++;
			}
			strncpy( qdir, path, c + len + count - path );
			Sys_Printf( "qdir: %s\n", qdir );
			for ( i = 0; i < strlen( qdir ); i++ )
			{
				if ( qdir[i] == '\\' ) {
					qdir[i] = '/';
				}
			}

			c += len + count;
			while ( *c )
			{
				if ( *c == '/' || *c == '\\' ) {
					strncpy( gamedir, path, c + 1 - path );

					for ( i = 0; i < strlen( gamedir ); i++ )
					{
						if ( gamedir[i] == '\\' ) {
							gamedir[i] = '/';
						}
					}

					Sys_Printf( "gamedir: %s\n", gamedir );

					if ( !writedir[0] ) {
						strcpy( writedir, gamedir );
					}
					else if ( writedir[strlen( writedir ) - 1] != '/' ) {
						writedir[strlen( writedir )] = '/';
						writedir[strlen( writedir ) + 1] = 0;
					}

					return;
				}
				c++;
			}
			Error( "No gamedir in %s", path );
			return;
		}
	}
	Error( "SetQdirFromPath: no '%s' in %s", BASEDIRNAME, path );
}

char *ExpandArg( const char *path ){
	static char full[1024];

	if ( path[0] != '/' && path[0] != '\\' && path[1] != ':' ) {
		Q_getwd( full );
		strcat( full, path );
	}
	else{
		strcpy( full, path );
	}
	return full;
}

char *ExpandPath( const char *path ){
	static char full[1024];
	if ( path[0] == '/' || path[0] == '\\' || path[1] == ':' ) {
		strcpy( full, path );
		return full;
	}
	sprintf( full, "%s%s", qdir, path );
	return full;
}

char *copystring( const char *s ){
	char    *b;
	b = safe_malloc( strlen( s ) + 1 );
	strcpy( b, s );
	return b;
}

double I_FloatTime( void ){
	time_t t;

	time( &t );

	return t;
#if 0
// more precise, less portable
	struct timeval tp;
	struct timezone tzp;
	static int secbase;

	gettimeofday( &tp, &tzp );

	if ( !secbase ) {
		secbase = tp.tv_sec;
		return tp.tv_usec / 1000000.0;
	}

	return ( tp.tv_sec - secbase ) + tp.tv_usec / 1000000.0;
#endif
}

void Q_getwd( char *out ){
	int i = 0;

#ifdef WIN32
	_getcwd( out, 256 );
	strcat( out, "\\" );
#else
	// Gef: Changed from getwd() to getcwd() to avoid potential buffer overflow
	getcwd( out, 256 );
	strcat( out, "/" );
#endif
	while ( out[i] != 0 )
	{
		if ( out[i] == '\\' ) {
			out[i] = '/';
		}
		i++;
	}
}

void Q_mkdir( const char *path ){
#ifdef WIN32
	if ( _mkdir( path ) != -1 ) {
		return;
	}
#else
	if ( mkdir( path, 0777 ) != -1 ) {
		return;
	}
#endif
	if ( errno != EEXIST ) {
		Error( "mkdir %s: %s",path, strerror( errno ) );
	}
}

int FileTime( const char *path ){
	struct  stat buf;

	if ( stat( path,&buf ) == -1 ) {
		return -1;
	}

	return buf.st_mtime;
}

char *COM_Parse( char *data ){
	int c;
	int len;

	len = 0;
	com_token[0] = 0;

	if ( !data ) {
		return NULL;
	}

// skip whitespace
skipwhite:
	while ( ( c = *data ) <= ' ' )
	{
		if ( c == 0 ) {
			com_eof = qtrue;
			return NULL;            // end of file;
		}
		data++;
	}

// skip // comments
	if ( c == '/' && data[1] == '/' ) {
		while ( *data && *data != '\n' )
			data++;
		goto skipwhite;
	}


// handle quoted strings specially
	if ( c == '\"' ) {
		data++;
		do
		{
			c = *data++;
			if ( c == '\"' ) {
				com_token[len] = 0;
				return data;
			}
			com_token[len] = c;
			len++;
		} while ( 1 );
	}

// parse single characters
	if ( c == '{' || c == '}' || c == ')' || c == '(' || c == '\'' || c == ':' ) {
		com_token[len] = c;
		len++;
		com_token[len] = 0;
		return data + 1;
	}

// parse a regular word
	do
	{
		com_token[len] = c;
		data++;
		len++;
		c = *data;
		if ( c == '{' || c == '}' || c == ')' || c == '(' || c == '\'' || c == ':' ) {
			break;
		}
	} while ( c > 32 );

	com_token[len] = 0;
	return data;
}

int Q_strncasecmp( const char *s1, const char *s2, int n ){
	int c1, c2;

	do
	{
		c1 = *s1++;
		c2 = *s2++;

		if ( !n-- ) {
			return 0;       // strings are equal until end point

		}
		if ( c1 != c2 ) {
			if ( c1 >= 'a' && c1 <= 'z' ) {
				c1 -= ( 'a' - 'A' );
			}
			if ( c2 >= 'a' && c2 <= 'z' ) {
				c2 -= ( 'a' - 'A' );
			}
			if ( c1 != c2 ) {
				return -1;      // strings not equal
			}
		}
	} while ( c1 );

	return 0;       // strings are equal
}

int Q_stricmp( const char *s1, const char *s2 ){
	return Q_strncasecmp( s1, s2, 99999 );
}

char *strlower( char *start ){
	char    *in;
	in = start;
	while ( *in )
	{
		*in = tolower( *in );
		in++;
	}
	return start;
}

int CheckParm( const char *check ){
	int i;

	for ( i = 1; i < myargc; i++ )
	{
		if ( !Q_stricmp( check, myargv[i] ) ) {
			return i;
		}
	}

	return 0;
}

int Q_filelength( FILE *f ){
	int pos;
	int end;

	pos = ftell( f );
	fseek( f, 0, SEEK_END );
	end = ftell( f );
	fseek( f, pos, SEEK_SET );

	return end;
}

FILE *SafeOpenWrite( const char *filename ){
	FILE    *f;

	f = fopen( filename, "wb" );

	if ( !f ) {
		Error( "Error opening %s: %s",filename,strerror( errno ) );
	}

	return f;
}

FILE *SafeOpenRead( const char *filename ){
	FILE    *f;

	f = fopen( filename, "rb" );

	if ( !f ) {
		Error( "Error opening %s: %s",filename,strerror( errno ) );
	}

	return f;
}

void SafeRead( FILE *f, void *buffer, int count ){
	if ( fread( buffer, 1, count, f ) != (size_t)count ) {
		Error( "File read failure" );
	}
}

void SafeWrite( FILE *f, const void *buffer, int count ){
	if ( fwrite( buffer, 1, count, f ) != (size_t)count ) {
		Error( "File write failure" );
	}
}

qboolean    FileExists( const char *filename ){
	FILE    *f;

	f = fopen( filename, "r" );
	if ( !f ) {
		return qfalse;
	}
	fclose( f );
	return qtrue;
}

int    LoadFile( const char *filename, void **bufferptr ){
	FILE    *f;
	int length;
	void    *buffer;

	f = SafeOpenRead( filename );
	length = Q_filelength( f );
	buffer = safe_malloc( length + 1 );
	( (char *)buffer )[length] = 0;
	SafeRead( f, buffer, length );
	fclose( f );

	*bufferptr = buffer;
	return length;
}

int    LoadFileBlock( const char *filename, void **bufferptr ){
	FILE    *f;
	int length, nBlock, nAllocSize;
	void    *buffer;

	f = SafeOpenRead( filename );
	length = Q_filelength( f );
	nAllocSize = length;
	nBlock = nAllocSize % MEM_BLOCKSIZE;
	if ( nBlock > 0 ) {
		nAllocSize += MEM_BLOCKSIZE - nBlock;
	}
	buffer = safe_malloc( nAllocSize + 1 );
	memset( buffer, 0, nAllocSize + 1 );
	SafeRead( f, buffer, length );
	fclose( f );

	*bufferptr = buffer;
	return length;
}

int    TryLoadFile( const char *filename, void **bufferptr ){
	FILE    *f;
	int length;
	void    *buffer;

	*bufferptr = NULL;

	f = fopen( filename, "rb" );
	if ( !f ) {
		return -1;
	}
	length = Q_filelength( f );
	buffer = safe_malloc( length + 1 );
	( (char *)buffer )[length] = 0;
	SafeRead( f, buffer, length );
	fclose( f );

	*bufferptr = buffer;
	return length;
}

void    SaveFile( const char *filename, const void *buffer, int count ){
	FILE    *f;

	f = SafeOpenWrite( filename );
	SafeWrite( f, buffer, count );
	fclose( f );
}

void DefaultExtension( char *path, const char *extension ){
	char    *src;
//
// if path doesnt have a .EXT, append extension
// (extension should include the .)
//
	src = path + strlen( path ) - 1;

	while ( *src != '/' && *src != '\\' && src != path )
	{
		if ( *src == '.' ) {
			return;                 // it has an extension
		}
		src--;
	}

	strcat( path, extension );
}

void DefaultPath( char *path, const char *basepath ){
	char temp[128];

	if ( path[ 0 ] == '/' || path[ 0 ] == '\\' ) {
		return;                   // absolute path location
	}
	strcpy( temp,path );
	strcpy( path,basepath );
	strcat( path,temp );
}

void    StripFilename( char *path ){
	int length;

	length = strlen( path ) - 1;
	while ( length > 0 && path[length] != '/' && path[ length ] != '\\' )
		length--;
	path[length] = 0;
}

void    StripExtension( char *path ){
	int length;

	length = strlen( path ) - 1;
	while ( length > 0 && path[length] != '.' )
	{
		length--;
		if ( path[length] == '/' || path[ length ] == '\\' ) {
			return;     // no extension
		}
	}
	if ( length ) {
		path[length] = 0;
	}
}

void ExtractFilePath( const char *path, char *dest ){
	const char    *src;

	src = path + strlen( path ) - 1;

//
// back up until a \ or the start
//
	while ( src != path && *( src - 1 ) != '\\' && *( src - 1 ) != '/' )
		src--;

	memcpy( dest, path, src - path );
	dest[src - path] = 0;
}

void ExtractFileBase( const char *path, char *dest ){
	const char    *src;

	src = path + strlen( path ) - 1;

//
// back up until a \ or the start
//
	while ( src != path && *( src - 1 ) != '/' && *( src - 1 ) != '\\' )
		src--;

	while ( *src && *src != '.' )
	{
		*dest++ = *src++;
	}
	*dest = 0;
}

void ExtractFileExtension( const char *path, char *dest ){
	const char    *src;

	src = path + strlen( path ) - 1;

//
// back up until a . or the start
//
	while ( src != path && *( src - 1 ) != '.' )
		src--;
	if ( src == path ) {
		*dest = 0;  // no extension
		return;
	}

	strcpy( dest,src );
}

int ParseHex( const char *hex ){
	const char    *str;
	int num;

	num = 0;
	str = hex;

	while ( *str )
	{
		num <<= 4;
		if ( *str >= '0' && *str <= '9' ) {
			num += *str - '0';
		}
		else if ( *str >= 'a' && *str <= 'f' ) {
			num += 10 + *str - 'a';
		}
		else if ( *str >= 'A' && *str <= 'F' ) {
			num += 10 + *str - 'A';
		}
		else{
			Error( "Bad hex number: %s",hex );
		}
		str++;
	}

	return num;
}

int ParseNum( const char *str ){
	if ( str[0] == '$' ) {
		return ParseHex( str + 1 );
	}
	if ( str[0] == '0' && str[1] == 'x' ) {
		return ParseHex( str + 2 );
	}
	return atol( str );
}

short   BigShort( short l ){
	byte b1,b2;

	b1 = l & 255;
	b2 = ( l >> 8 ) & 255;

	return ( b1 << 8 ) + b2;
}

short   LittleShort( short l ){
	return l;
}

int    BigLong( int l ){
	byte b1,b2,b3,b4;

	b1 = l & 255;
	b2 = ( l >> 8 ) & 255;
	b3 = ( l >> 16 ) & 255;
	b4 = ( l >> 24 ) & 255;

	return ( (int)b1 << 24 ) + ( (int)b2 << 16 ) + ( (int)b3 << 8 ) + b4;
}

int    LittleLong( int l ){
	return l;
}

float   BigFloat( float l ){
	union {byte b[4]; float f; } in, out;

	in.f = l;
	out.b[0] = in.b[3];
	out.b[1] = in.b[2];
	out.b[2] = in.b[1];
	out.b[3] = in.b[0];

	return out.f;
}

float   LittleFloat( float l ){
	return l;
}

void CRC_Init( unsigned short *crcvalue ){
	*crcvalue = CRC_INIT_VALUE;
}

void CRC_ProcessByte( unsigned short *crcvalue, byte data ){
	*crcvalue = ( *crcvalue << 8 ) ^ crctable[( *crcvalue >> 8 ) ^ data];
}

unsigned short CRC_Value( unsigned short crcvalue ){
	return crcvalue ^ CRC_XOR_VALUE;
}

void    CreatePath( const char *path ){
	const char  *ofs;
	char c;
	char dir[1024];

#ifdef _WIN32
	int olddrive = -1;

	if ( path[1] == ':' ) {
		olddrive = _getdrive();
		_chdrive( toupper( path[0] ) - 'A' + 1 );
	}
#endif

	if ( path[1] == ':' ) {
		path += 2;
	}

	for ( ofs = path + 1 ; *ofs ; ofs++ )
	{
		c = *ofs;
		if ( c == '/' || c == '\\' ) { // create the directory
			memcpy( dir, path, ofs - path );
			dir[ ofs - path ] = 0;
			Q_mkdir( dir );
		}
	}

#ifdef _WIN32
	if ( olddrive != -1 ) {
		_chdrive( olddrive );
	}
#endif
}

void QCopyFile( const char *from, const char *to ){
	void    *buffer;
	int length;

	length = LoadFile( from, &buffer );
	CreatePath( to );
	SaveFile( to, buffer, length );
	free( buffer );
}

void Sys_Sleep( int n ){
#ifdef WIN32
	Sleep( n );
#endif
#if defined( __linux__ ) || defined( __FreeBSD__ ) || defined( __APPLE__ )
	usleep( n * 1000 );
#endif
}

