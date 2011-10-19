#include	<windows.h>

#define	MESSAGETYPE_JAPANESE		/* if you defined, message is Japanese. */

#ifndef	bool
#define	bool	int
#endif
#ifndef	true
#define	true	1
#endif
#ifndef	false
#define	false	0
#endif

/*
[HEADER FORMAT]

0000 3BYTE	MAGIC 'S98'
0003 1BYTE	FORMAT VERSION '1' or '0'
0004 DWORD(LE)	TIMER INFO sync time(ms) If value is 0, default time is 10ms.
0008 DWORD(LE)	RESERVE FOR TIMER INFO 2
000C DWORD(LE)	COMPRESSING 'Inflate' size in byte.If value is 0, notcompressed.
0010 DWORD(LE)	FILE OFFSET TO SONG NAME If value is 0, no title exist.
0014 DWORD(LE)	FILE OFFSET TO DUMP DATA
0018 DWORD(LE)	FILE OFFSET TO LOOP POINT DUMP DATA
001C-003F	HEADER RESERVE
*/
typedef struct {
	char	MAGIC[3];
	char	FormatVer;
	DWORD	Sync1;
	DWORD	Sync2;
	DWORD	CompSize;
	DWORD	SongNameOffset;
	DWORD	DumpDataOffset;
	DWORD	LoopPointOffset;
} S98HEAD;

/*
[DUMP DATA FORMAT]

00 aa dd OPNA(master)
01 aa dd OPNA(slave)
FF        1SYNC
FE vv     nSYNC
FD        END/LOOP
*/

typedef struct {
	DWORD	Offset;			/* data offset		*/
	DWORD	Time;			/* Play Time(mSec)	*/
	char	OPNAData[3+1];
} S98DATA;


