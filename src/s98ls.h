#include	"stdint.h"
#include	"stdbool.h"

//#define	MESSAGETYPE_JAPANESE		/* if you defined, message is Japanese. */

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
	uint32_t	Sync1;
	uint32_t	Sync2;
	uint32_t	CompSize;
	uint32_t	SongNameOffset;
	uint32_t	DumpDataOffset;
	uint32_t	LoopPointOffset;
	uint32_t	DeviceCount;
} S98HEAD;

typedef struct {
	uint32_t	DevType;
	uint32_t	DevClk;
	uint32_t	DevPan;
	char	Reserve[4];
} S98DEV;

/*
[DUMP DATA FORMAT]

00 aa dd OPNA(master)
01 aa dd OPNA(slave)
FF        1SYNC
FE vv     nSYNC
FD        END/LOOP
*/

typedef struct {
	uint32_t	Offset;			/* data offset		*/
	uint32_t	Time;			/* Play Time(mSec)	*/
	char	OPNAData[3+1];
} S98DATA;


