#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char* arg; char* gamePath; char* magic; char* homeBasePath; } ;
typedef  TYPE_1__ game_t ;

/* Variables and functions */
 int /*<<< orphan*/  Error (char*,...) ; 
 size_t MAX_BASE_PATHS ; 
 size_t MAX_GAME_PATHS ; 
 int MAX_OS_PATH ; 
 scalar_t__ Q_stricmp (char*,char*) ; 
 scalar_t__ Q_strncasecmp (char*,char*,int) ; 
 int /*<<< orphan*/  SYS_VRB ; 
 int /*<<< orphan*/  Sys_FPrintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  Sys_Printf (char*) ; 
 char** basePaths ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 TYPE_1__* game ; 
 char** gamePaths ; 
 TYPE_1__* games ; 
 char* installPath ; 
 size_t numBasePaths ; 
 size_t numGamePaths ; 
 char* safe_malloc (int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char*) ; 
 int unz_GAME_QL ; 
 int /*<<< orphan*/  vfsInitDirectory (char*) ; 

char *LokiGetHomeDir( void ){
	#ifndef Q_UNIX
	return NULL;
	#else
	static char	buf[ 4096 ];
	struct passwd   pw, *pwp;
	char            *home;


	/* get the home environment variable */
	home = getenv( "HOME" );
	if ( home ) {
		return Q_strncpyz( buf, home, sizeof( buf ) );
	}

	/* look up home dir in password database */
	if ( getpwuid_r( getuid(), &pw, buf, sizeof( buf ), &pwp ) == 0 ) {
		return pw.pw_dir;
	}

	return NULL;
	#endif
}

void LokiInitPaths( char *argv0 ){
	#ifndef Q_UNIX
	/* this is kinda crap, but hey */
	strcpy( installPath, "../" );
	#else
	char temp[ MAX_OS_PATH ];
	char        *home;
	char        *path;
	char        *last;
	qboolean found;


	/* get home dir */
	home = LokiGetHomeDir();
	if ( home == NULL ) {
		home = ".";
	}

	path = getenv( "PATH" );

	/* do some path divining */
	Q_strncpyz( temp, argv0, sizeof( temp ) );
	if ( strrchr( temp, '/' ) ) {
		argv0 = strrchr( argv0, '/' ) + 1;
	}
	else if ( path ) {
		found = qfalse;
		last = path;

		/* go through each : segment of path */
		while ( last[ 0 ] != '\0' && found == qfalse )
		{
			/* null out temp */
			temp[ 0 ] = '\0';

			/* find next chunk */
			last = strchr( path, ':' );
			if ( last == NULL ) {
				last = path + strlen( path );
			}

			/* found home dir candidate */
			if ( *path == '~' ) {
				Q_strncpyz( temp, home, sizeof( temp ) );
				path++;
			}

			/* concatenate */
			if ( last > ( path + 1 ) ) {
				Q_strncat( temp, sizeof( temp ), path, ( last - path ) );
				Q_strcat( temp, sizeof( temp ), "/" );
			}
			Q_strcat( temp, sizeof( temp ), "./" );
			Q_strcat( temp, sizeof( temp ), argv0 );

			/* verify the path */
			if ( access( temp, X_OK ) == 0 ) {
				found++;
			}
			path = last + 1;
		}
	}

	/* flake */
	if ( realpath( temp, installPath ) ) {
		/* q3map is in "tools/" */
		*( strrchr( installPath, '/' ) ) = '\0';
		*( strrchr( installPath, '/' ) + 1 ) = '\0';
	}

	/* set home path */
	homePath = home;
	#endif
}

void CleanPath( char *path ){
	while ( *path )
	{
		if ( *path == '\\' ) {
			*path = '/';
		}
		path++;
	}
}

game_t *GetGame( char *arg ){
	int i;


	/* dummy check */
	if ( arg == NULL || arg[ 0 ] == '\0' ) {
		return NULL;
	}

	/* joke */
	if ( !Q_stricmp( arg, "quake1" ) ||
		 !Q_stricmp( arg, "quake2" ) ||
		 !Q_stricmp( arg, "unreal" ) ||
		 !Q_stricmp( arg, "ut2k3" ) ||
		 !Q_stricmp( arg, "dn3d" ) ||
		 !Q_stricmp( arg, "dnf" ) ||
		 !Q_stricmp( arg, "hl" ) ) {
		Sys_Printf( "April fools, silly rabbit!\n" );
		exit( 0 );
	}

	/* test it */
	i = 0;
	while ( games[ i ].arg != NULL )
	{
		if ( Q_stricmp( arg, games[ i ].arg ) == 0 ) {
			return &games[ i ];
		}
		i++;
	}

	/* no matching game */
	return NULL;
}

void AddBasePath( char *path ){
	/* dummy check */
	if ( path == NULL || path[ 0 ] == '\0' || numBasePaths >= MAX_BASE_PATHS ) {
		return;
	}

	/* add it to the list */
	basePaths[ numBasePaths ] = safe_malloc( strlen( path ) + 1 );
	strcpy( basePaths[ numBasePaths ], path );
	CleanPath( basePaths[ numBasePaths ] );
	numBasePaths++;
}

void AddHomeBasePath( char *path ){
	#ifdef Q_UNIX
	int i;
	char temp[ MAX_OS_PATH ];


	/* dummy check */
	if ( path == NULL || path[ 0 ] == '\0' ) {
		return;
	}

	/* make a hole */
	for ( i = 0; i < ( MAX_BASE_PATHS - 1 ); i++ )
		basePaths[ i + 1 ] = basePaths[ i ];

	/* concatenate home dir and path */
	sprintf( temp, "%s/%s", homePath, path );

	/* add it to the list */
	basePaths[ 0 ] = safe_malloc( strlen( temp ) + 1 );
	strcpy( basePaths[ 0 ], temp );
	CleanPath( basePaths[ 0 ] );
	numBasePaths++;
	#endif
}

void AddGamePath( char *path ){
	int i;

	/* dummy check */
	if ( path == NULL || path[ 0 ] == '\0' || numGamePaths >= MAX_GAME_PATHS ) {
		return;
	}

	/* add it to the list */
	gamePaths[ numGamePaths ] = safe_malloc( strlen( path ) + 1 );
	strcpy( gamePaths[ numGamePaths ], path );
	CleanPath( gamePaths[ numGamePaths ] );
	numGamePaths++;

	/* don't add it if it's already there */
	for ( i = 0; i < numGamePaths - 1; i++ )
	{
		if ( strcmp( gamePaths[i], gamePaths[numGamePaths - 1] ) == 0 ) {
			free( gamePaths[numGamePaths - 1] );
			gamePaths[numGamePaths - 1] = NULL;
			numGamePaths--;
			break;
		}
	}

}

void InitPaths( int *argc, char **argv ){
	int i, j, k, len, len2;
	char temp[ MAX_OS_PATH ];

	/* note it */
	Sys_FPrintf( SYS_VRB, "--- InitPaths ---\n" );

	/* get the install path for backup */
	LokiInitPaths( argv[ 0 ] );

	/* set game to default (q3a) */
	game = &games[ 0 ];
	numBasePaths = 0;
	numGamePaths = 0;

	/* parse through the arguments and extract those relevant to paths */
	for ( i = 0; i < *argc; i++ )
	{
		/* check for null */
		if ( argv[ i ] == NULL ) {
			continue;
		}

		/* -game */
		if ( strcmp( argv[ i ], "-game" ) == 0 ) {
			if ( ++i >= *argc ) {
				Error( "Out of arguments: No game specified after %s", argv[ i - 1 ] );
			}
			argv[ i - 1 ] = NULL;
			game = GetGame( argv[ i ] );
			if ( game == NULL ) {
				game = &games[ 0 ];
			}
			argv[ i ] = NULL;
		}

		/* -fs_basepath */
		else if ( strcmp( argv[ i ], "-fs_basepath" ) == 0 ) {
			if ( ++i >= *argc ) {
				Error( "Out of arguments: No path specified after %s.", argv[ i - 1 ] );
			}
			argv[ i - 1 ] = NULL;
			AddBasePath( argv[ i ] );
			argv[ i ] = NULL;
		}

		/* -fs_game */
		else if ( strcmp( argv[ i ], "-fs_game" ) == 0 ) {
			if ( ++i >= *argc ) {
				Error( "Out of arguments: No path specified after %s.", argv[ i - 1 ] );
			}
			argv[ i - 1 ] = NULL;
			AddGamePath( argv[ i ] );
			argv[ i ] = NULL;
		}
	}

	/* remove processed arguments */
	for ( i = 0, j = 0, k = 0; i < *argc && j < *argc; i++, j++ )
	{
		for ( ; j < *argc && argv[ j ] == NULL; j++ ) ;
		argv[ i ] = argv[ j ];
		if ( argv[ i ] != NULL ) {
			k++;
		}
	}
	*argc = k;

	/* add standard game path */
	AddGamePath( game->gamePath );

	/* if there is no base path set, figure it out */
	if ( numBasePaths == 0 ) {
		/* this is another crappy replacement for SetQdirFromPath() */
		len2 = strlen( game->magic );
		for ( i = 0; i < *argc && numBasePaths == 0; i++ )
		{
			/* extract the arg */
			strcpy( temp, argv[ i ] );
			CleanPath( temp );
			len = strlen( temp );
			Sys_FPrintf( SYS_VRB, "Searching for \"%s\" in \"%s\" (%d)...\n", game->magic, temp, i );

			/* this is slow, but only done once */
			for ( j = 0; j < ( len - len2 ); j++ )
			{
				/* check for the game's magic word */
				if ( Q_strncasecmp( &temp[ j ], game->magic, len2 ) == 0 ) {
					/* now find the next slash and nuke everything after it */
					while ( temp[ ++j ] != '/' && temp[ j ] != '\0' ) ;
					temp[ j ] = '\0';

					/* add this as a base path */
					AddBasePath( temp );
					break;
				}
			}
		}

		/* add install path */
		if ( numBasePaths == 0 ) {
			AddBasePath( installPath );
		}

		/* check again */
		if ( numBasePaths == 0 ) {
			Error( "Failed to find a valid base path." );
		}
	}

	/* this only affects unix */
	AddHomeBasePath( game->homeBasePath );

	/* initialize vfs paths */
	if ( numBasePaths > MAX_BASE_PATHS ) {
		numBasePaths = MAX_BASE_PATHS;
	}
	if ( numGamePaths > MAX_GAME_PATHS ) {
		numGamePaths = MAX_GAME_PATHS;
	}

	/* walk the list of game paths */
	for ( j = 0; j < numGamePaths; j++ )
	{
		/* walk the list of base paths */
		for ( i = 0; i < numBasePaths; i++ )
		{
			/* create a full path and initialize it */
			sprintf( temp, "%s/%s/", basePaths[ i ], gamePaths[ j ] );
			//quick n dirty patch to enable vfs for quakelive
			if (strcmp(game->arg, "quakelive") == 0 ) {
				unz_GAME_QL = 1;
			} else {
				unz_GAME_QL = 0;
			}
			vfsInitDirectory( temp );
		}
	}

	/* done */
	Sys_Printf( "\n" );
}

