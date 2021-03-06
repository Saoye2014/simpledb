/*
** 2015 Dec
** This header file defines the interface that the minidb cache subsystem
*/

#ifndef MNDB_PAGE_SIZE 
#define MNDB_PAGE_SIZE 1024
#endif

#ifndef MNDB_PAGE_RESERVE 
#define MNDB_PAGE_RESERVE 0
#endif

#ifndef MNDB_PAGE_USABLE_SIZE
#define MNDB_PAGE_USABLE_SIZE MNDB_PAGE_SIZE - MNDB_PAGE_RESERVE
#endif

#ifndef MNDB_MAX_PAGE
#define MNDB_MAX_PAGE 1077741823
#endif

/* The type used to represent a page number, The  firsrt page in a file
** is called page 1
*/
typedef unsigned int Pgno;

/*
** Each open file is managed by a seperate instance of the "Pager" structure
*/
typedef struct Pager Pager;

/* 
** Routines of pager
*/
int mndbpager_open(Pager **ppPager, const char *zFilename, int mxPage, int nEx);
void mndbpager_set_destructor(Pager *pPager, void (*Desc)(void *));
int mndbpager_pagecount(Pager *pPager);
int mndbpager_close(Pager *pPager);
Pgno mndbpager_pagenumber(void *pData);
int mndbpager_ref(void *pData);
int mndbpager_get(Pager *pPager, Pgno pgno, void **ppPage);
void* mndbpager_lookup(Pager *pPager, Pgno pgno);
int mndbpager_unref(void *pData);
int mndbpager_begin(void *pData);
int mndbpager_write(void *pData);
int mndbpager_iswriteable(void *pData);
int mndbpager_overwrite(Pager *pPager, Pgno pgno, void *pData);
int mndbpager_commit(Pager *pPager);
int mndbpager_isreadonly(Pager *pPager);
int* mndbpager_stats(Pager *pPager);
const char* mndbpager_filename(Pager *pPager);
#ifdef TEST
void mndbpager_refdump(Pager*);
int pager_refinfo_enable;
#endif























