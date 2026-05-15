#pragma once
#ifndef _GAME_MEMORY_H_ 
#define _GAME_MEMORY_H_

#define DISABLE_MEMORYPOOL_CHECKPOINTING 1

#if (defined(_DEBUG) || defined(_INTERNAL)) && !defined(MEMORYPOOL_DEBUG_CUSTOM_NEW) && !defined(DISABLE_MEMORYPOOL_DEBUG_CUSTOM_NEW)
        #define MEMORYPOOL_DEBUG_CUSTOM_NEW
#endif

#if (defined(_DEBUG)) && !defined(MEMORYPOOL_DEBUG) && !defined(DISABLE_MEMORYPOOL_DEBUG)
        #define MEMORYPOOL_DEBUG
#endif

#include <new>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Lib/BaseType.h"
#include "Common/Debug.h"
#include "Common/Errors.h"

#ifdef MEMORYPOOL_DEBUG

        #ifndef DISABLE_MEMORYPOOL_CHECKPOINTING
                #define MEMORYPOOL_CHECKPOINTING
        #endif

        #ifndef DISABLE_MEMORYPOOL_BOUNDINGWALL
                #define MEMORYPOOL_BOUNDINGWALL
        #endif

        #define DECLARE_LITERALSTRING_ARG1                                                                              const char * debugLiteralTagString
        #define PASS_LITERALSTRING_ARG1                                                                                         debugLiteralTagString
        #define DECLARE_LITERALSTRING_ARG2                                                                              , const char * debugLiteralTagString
        #define PASS_LITERALSTRING_ARG2                                                                                         , debugLiteralTagString

        #define MP_LOC_SUFFIX

        #define allocateBlock(ARGLITERAL)                                                                               allocateBlockImplementation(ARGLITERAL MP_LOC_SUFFIX)
        #define allocateBlockDoNotZero(ARGLITERAL)                                      allocateBlockDoNotZeroImplementation(ARGLITERAL MP_LOC_SUFFIX)
        #define allocateBytes(ARGCOUNT,ARGLITERAL)                                      allocateBytesImplementation(ARGCOUNT, ARGLITERAL MP_LOC_SUFFIX)
        #define allocateBytesDoNotZero(ARGCOUNT,ARGLITERAL)     allocateBytesDoNotZeroImplementation(ARGCOUNT, ARGLITERAL MP_LOC_SUFFIX)
        #define newInstanceDesc(ARGCLASS,ARGLITERAL)                            new(ARGCLASS::ARGCLASS##_GLUE_NOT_IMPLEMENTED, ARGLITERAL MP_LOC_SUFFIX) ARGCLASS
        #define newInstance(ARGCLASS)                                                                                           new(ARGCLASS::ARGCLASS##_GLUE_NOT_IMPLEMENTED, __FILE__) ARGCLASS

        #if !defined(MEMORYPOOL_STACKTRACE) && !defined(DISABLE_MEMORYPOOL_STACKTRACE)
                #define MEMORYPOOL_STACKTRACE
        #endif

        enum {
                _REPORT_CP_ALLOCATED_BEFORE             = 0x0001,
                _REPORT_CP_ALLOCATED_BETWEEN    = 0x0002,
                _REPORT_CP_ALLOCATED_DONTCARE   = (_REPORT_CP_ALLOCATED_BEFORE|_REPORT_CP_ALLOCATED_BETWEEN),
                _REPORT_CP_FREED_BEFORE                 = 0x0010,
                _REPORT_CP_FREED_BETWEEN                = 0x0020,
                _REPORT_CP_FREED_NEVER                  = 0x0040,
                _REPORT_CP_FREED_DONTCARE               = (_REPORT_CP_FREED_BEFORE|_REPORT_CP_FREED_BETWEEN|_REPORT_CP_FREED_NEVER),
                REPORT_CP_STACKTRACE                    = 0x0100,
                REPORT_POOLINFO                                 = 0x0200,
                REPORT_FACTORYINFO                              = 0x0400,
                REPORT_POOL_OVERFLOW                    = 0x0800,
                REPORT_SIMPLE_LEAKS                             = 0x1000,
                REPORT_CP_ALLOCATES                             = (_REPORT_CP_ALLOCATED_BETWEEN | _REPORT_CP_FREED_DONTCARE),
                REPORT_CP_FREES                                 = (_REPORT_CP_ALLOCATED_DONTCARE | _REPORT_CP_FREED_BETWEEN),
                REPORT_CP_LEAKS                                 = (_REPORT_CP_ALLOCATED_BETWEEN | _REPORT_CP_FREED_NEVER),
                REPORT_CP_LONGTERM                              = (_REPORT_CP_ALLOCATED_BEFORE | _REPORT_CP_FREED_NEVER),
                REPORT_CP_TRANSIENT                             = (_REPORT_CP_ALLOCATED_BETWEEN | _REPORT_CP_FREED_BETWEEN),
                REPORT_CP_EXISTING                              = (_REPORT_CP_ALLOCATED_BEFORE | _REPORT_CP_ALLOCATED_BETWEEN | _REPORT_CP_FREED_NEVER),
                REPORT_CP_ALL                                   = (_REPORT_CP_ALLOCATED_DONTCARE | _REPORT_CP_FREED_DONTCARE)
        };

#else

        #define DECLARE_LITERALSTRING_ARG1
        #define PASS_LITERALSTRING_ARG1 
        #define DECLARE_LITERALSTRING_ARG2
        #define PASS_LITERALSTRING_ARG2

        #define allocateBlock(ARGLITERAL)                                                                               allocateBlockImplementation()
        #define allocateBlockDoNotZero(ARGLITERAL)                                      allocateBlockDoNotZeroImplementation()
        #define allocateBytes(ARGCOUNT,ARGLITERAL)                                      allocateBytesImplementation(ARGCOUNT)
        #define allocateBytesDoNotZero(ARGCOUNT,ARGLITERAL)     allocateBytesDoNotZeroImplementation(ARGCOUNT)
        #define newInstanceDesc(ARGCLASS,ARGLITERAL)                            new(ARGCLASS::ARGCLASS##_GLUE_NOT_IMPLEMENTED) ARGCLASS
        #define newInstance(ARGCLASS)                                                                                           new(ARGCLASS::ARGCLASS##_GLUE_NOT_IMPLEMENTED) ARGCLASS

#endif

class MemoryPoolSingleBlock;
class MemoryPoolBlob;
class MemoryPool;
class MemoryPoolFactory;
class DynamicMemoryAllocator;
class BlockCheckpointInfo;

struct PoolInitRec {
        const char *poolName;
        Int allocationSize;
        Int initialAllocationCount;
        Int overflowAllocationCount;
};

enum {
        MAX_DYNAMICMEMORYALLOCATOR_SUBPOOLS = 8
};

#ifdef MEMORYPOOL_CHECKPOINTING
class Checkpointable {
private:
        BlockCheckpointInfo *m_firstCheckpointInfo;
        Bool m_cpiEverFailed;
protected:
        Checkpointable();
        ~Checkpointable();
        BlockCheckpointInfo *debugAddCheckpointInfo(const char *debugLiteralTagString, Int allocCheckpoint, Int blockSize);
public:
        void debugCheckpointReport(Int flags, Int startCheckpoint, Int endCheckpoint, const char *poolName);
        void debugResetCheckpoints();
};
#endif

class MemoryPool
#ifdef MEMORYPOOL_CHECKPOINTING
        : public Checkpointable
#endif
{
private:
        MemoryPoolFactory *m_factory;
        MemoryPool *m_nextPoolInFactory;
        const char *m_poolName;
        Int m_allocationSize;
        Int m_initialAllocationCount;
        Int m_overflowAllocationCount;
        Int m_usedBlocksInPool;
        Int m_totalBlocksInPool;
        Int m_peakUsedBlocksInPool;
        MemoryPoolBlob *m_firstBlob;
        MemoryPoolBlob *m_lastBlob;
        MemoryPoolBlob *m_firstBlobWithFreeBlocks;
private:
        MemoryPoolBlob* createBlob(Int allocationCount);
        Int freeBlob(MemoryPoolBlob *blob);
public:
        MemoryPool *getNextPoolInList();
        void addToList(MemoryPool **pHead);
        void removeFromList(MemoryPool **pHead);
        #ifdef MEMORYPOOL_DEBUG
                static void debugPoolInfoReport(MemoryPool *pool, FILE *fp = NULL);
                const char *debugGetBlockTagString(void *pBlock);
                void debugMemoryVerifyPool();
                Int debugPoolReportLeaks(const char* owner);
        #endif
        #ifdef MEMORYPOOL_CHECKPOINTING
                void debugResetCheckpoints();
        #endif
public:
        MemoryPool();
        void init(MemoryPoolFactory *factory, const char *poolName, Int allocationSize, Int initialAllocationCount, Int overflowAllocationCount);
        ~MemoryPool();
        void *allocateBlockImplementation(DECLARE_LITERALSTRING_ARG1);
        void *allocateBlockDoNotZeroImplementation(DECLARE_LITERALSTRING_ARG1);
        void freeBlock(void *pMem);
        MemoryPoolFactory *getOwningFactory();
        const char *getPoolName();
        Int getAllocationSize();
        Int getFreeBlockCount();
        Int getUsedBlockCount();
        Int getTotalBlockCount();
        Int getPeakBlockCount();
        Int getInitialBlockCount();
        Int countBlobsInPool();
        Int releaseEmpties();
        void reset();
        #ifdef MEMORYPOOL_DEBUG
                Bool debugIsBlockInPool(void *pBlock);
        #endif
};

class DynamicMemoryAllocator
#ifdef MEMORYPOOL_CHECKPOINTING
        : public Checkpointable
#endif
{
private:
        MemoryPoolFactory *m_factory;
        DynamicMemoryAllocator *m_nextDmaInFactory;
        Int m_numPools;
        Int m_usedBlocksInDma;
        MemoryPool *m_pools[MAX_DYNAMICMEMORYALLOCATOR_SUBPOOLS];
        MemoryPoolSingleBlock *m_rawBlocks;
        MemoryPool *findPoolForSize(Int allocSize);
public:
        DynamicMemoryAllocator *getNextDmaInList();
        void addToList(DynamicMemoryAllocator **pHead);
        void removeFromList(DynamicMemoryAllocator **pHead);
        #ifdef MEMORYPOOL_DEBUG
                Int debugCalcRawBlockBytes(Int *numBlocks);
                void debugMemoryVerifyDma();
                const char *debugGetBlockTagString(void *pBlock);
                void debugDmaInfoReport(FILE *fp = NULL);
                Int debugDmaReportLeaks();
        #endif
        #ifdef MEMORYPOOL_CHECKPOINTING
                void debugResetCheckpoints();
        #endif
public:
        DynamicMemoryAllocator();
        void init(MemoryPoolFactory *factory, Int numSubPools, const PoolInitRec pParms[]);
        ~DynamicMemoryAllocator();
        void *allocateBytesImplementation(Int numBytes DECLARE_LITERALSTRING_ARG2);
        void *allocateBytesDoNotZeroImplementation(Int numBytes DECLARE_LITERALSTRING_ARG2);
        #ifdef MEMORYPOOL_DEBUG
                void debugIgnoreLeaksForThisBlock(void* pBlockPtr);
        #endif
        void freeBytes(void* pMem);
        Int getActualAllocationSize(Int numBytes);
        void reset();
        Int getDmaMemoryPoolCount() const { return m_numPools; }
        MemoryPool* getNthDmaMemoryPool(Int i) const { return m_pools[i]; }
        #ifdef MEMORYPOOL_DEBUG
                Bool debugIsBlockInDma(void *pBlock);
                Bool debugIsPoolInDma(MemoryPool *pool);
        #endif
};

#ifdef MEMORYPOOL_DEBUG
enum { MAX_SPECIAL_USED = 256 };
#endif

class MemoryPoolFactory {
private:
        MemoryPool *m_firstPoolInFactory;
        DynamicMemoryAllocator *m_firstDmaInFactory;
        #ifdef MEMORYPOOL_CHECKPOINTING
                Int m_curCheckpoint;
        #endif
        #ifdef MEMORYPOOL_DEBUG
                Int m_usedBytes;
                Int m_physBytes;
                Int m_peakUsedBytes;
                Int m_peakPhysBytes;
                Int m_usedBytesSpecial[MAX_SPECIAL_USED];
                Int m_usedBytesSpecialPeak[MAX_SPECIAL_USED];
                Int m_physBytesSpecial[MAX_SPECIAL_USED];
                Int m_physBytesSpecialPeak[MAX_SPECIAL_USED];
        #endif
public:
        #ifdef MEMORYPOOL_DEBUG
                void adjustTotals(const char* tagString, Int usedDelta, Int physDelta);
        #endif
        #ifdef MEMORYPOOL_CHECKPOINTING
                Int getCurCheckpoint() { return m_curCheckpoint; }
        #endif
public:
        MemoryPoolFactory();
        void init();
        ~MemoryPoolFactory();
        MemoryPool *createMemoryPool(const PoolInitRec *parms);
        MemoryPool *createMemoryPool(const char *poolName, Int allocationSize, Int initialAllocationCount, Int overflowAllocationCount);
        MemoryPool *findMemoryPool(const char *poolName);
        void destroyMemoryPool(MemoryPool *pMemoryPool);
        DynamicMemoryAllocator *createDynamicMemoryAllocator(Int numSubPools, const PoolInitRec pParms[]);
        void destroyDynamicMemoryAllocator(DynamicMemoryAllocator *dma);
        void reset();
        void memoryPoolUsageReport(const char* filename, FILE *appendToFileInstead = NULL);
        #ifdef MEMORYPOOL_DEBUG
                void debugMemoryVerify();
                Bool debugIsBlockInAnyPool(void *pBlock);
                const char *debugGetBlockTagString(void *pBlock);
                void debugMemoryReport(Int flags, Int startCheckpoint, Int endCheckpoint, FILE *fp = NULL);
                void debugSetInitFillerIndex(Int index);
        #endif
        #ifdef MEMORYPOOL_CHECKPOINTING
                Int debugSetCheckpoint();
                void debugResetCheckpoints();
        #endif
};

#define MEMORY_POOL_OBJECT_ALLOCATION_SLOP      16

#define GCMP_FIND(ARGCLASS, ARGPOOLNAME) \
private: \
        static MemoryPool *getClassMemoryPool() { \
                DEBUG_ASSERTCRASH(TheMemoryPoolFactory, ("TheMemoryPoolFactory is NULL\n")); \
                static MemoryPool *The##ARGCLASS##Pool = TheMemoryPoolFactory->findMemoryPool(ARGPOOLNAME); \
                DEBUG_ASSERTCRASH(The##ARGCLASS##Pool, ("Pool \"%s\" not found (did you set it up in initMemoryPools?)\n", ARGPOOLNAME)); \
                DEBUG_ASSERTCRASH(The##ARGCLASS##Pool->getAllocationSize() >= sizeof(ARGCLASS), ("Pool \"%s\" is too small for this class (currently %d, need %zu)\n", ARGPOOLNAME, The##ARGCLASS##Pool->getAllocationSize(), sizeof(ARGCLASS))); \
                DEBUG_ASSERTCRASH(The##ARGCLASS##Pool->getAllocationSize() <= sizeof(ARGCLASS)+MEMORY_POOL_OBJECT_ALLOCATION_SLOP, ("Pool \"%s\" is too large for this class (currently %d, need %zu)\n", ARGPOOLNAME, The##ARGCLASS##Pool->getAllocationSize(), sizeof(ARGCLASS))); \
                return The##ARGCLASS##Pool; \
        }

#define GCMP_CREATE(ARGCLASS, ARGPOOLNAME, ARGINITIAL, ARGOVERFLOW) \
private: \
        static MemoryPool *getClassMemoryPool() { \
                DEBUG_ASSERTCRASH(TheMemoryPoolFactory, ("TheMemoryPoolFactory is NULL\n")); \
                static MemoryPool *The##ARGCLASS##Pool = TheMemoryPoolFactory->createMemoryPool(ARGPOOLNAME, sizeof(ARGCLASS), ARGINITIAL, ARGOVERFLOW); \
                DEBUG_ASSERTCRASH(The##ARGCLASS##Pool, ("Pool \"%s\" not found (did you set it up in initMemoryPools?)\n", ARGPOOLNAME)); \
                DEBUG_ASSERTCRASH(The##ARGCLASS##Pool->getAllocationSize() >= sizeof(ARGCLASS), ("Pool \"%s\" is too small for this class (currently %d, need %zu)\n", ARGPOOLNAME, The##ARGCLASS##Pool->getAllocationSize(), sizeof(ARGCLASS))); \
                DEBUG_ASSERTCRASH(The##ARGCLASS##Pool->getAllocationSize() <= sizeof(ARGCLASS)+MEMORY_POOL_OBJECT_ALLOCATION_SLOP, ("Pool \"%s\" is too large for this class (currently %d, need %zu)\n", ARGPOOLNAME, The##ARGCLASS##Pool->getAllocationSize(), sizeof(ARGCLASS))); \
                return The##ARGCLASS##Pool; \
        }

#define MEMORY_POOL_GLUE_WITHOUT_GCMP(ARGCLASS) \
protected: \
        virtual ~ARGCLASS(); \
public: \
        enum ARGCLASS##MagicEnum { ARGCLASS##_GLUE_NOT_IMPLEMENTED = 0 }; \
public: \
        inline void *operator new(size_t s, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) { \
                DEBUG_ASSERTCRASH(s == sizeof(ARGCLASS), ("The wrong operator new is being called")); \
                return ARGCLASS::getClassMemoryPool()->allocateBlockImplementation(PASS_LITERALSTRING_ARG1); \
        } \
public: \
        inline void operator delete(void *p, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) { \
                ARGCLASS::getClassMemoryPool()->freeBlock(p); \
        } \
protected: \
        inline void *operator new(size_t s) { \
                DEBUG_CRASH(("This operator new should normally never be called... please use new(char*) instead.")); \
                DEBUG_ASSERTCRASH(s == sizeof(ARGCLASS), ("The wrong operator new is being called")); \
                throw ERROR_BUG; \
                return 0; \
        } \
        inline void operator delete(void *p) { \
                DEBUG_CRASH(("Please call deleteInstance instead of delete.")); \
                ARGCLASS::getClassMemoryPool()->freeBlock(p); \
        } \
private: \
        virtual MemoryPool *getObjectMemoryPool() { \
                return ARGCLASS::getClassMemoryPool(); \
        } \
public:

#define MEMORY_POOL_GLUE(ARGCLASS, ARGPOOLNAME) \
        MEMORY_POOL_GLUE_WITHOUT_GCMP(ARGCLASS) \
        GCMP_FIND(ARGCLASS, ARGPOOLNAME)

#define MEMORY_POOL_GLUE_WITH_EXPLICIT_CREATE(ARGCLASS, ARGPOOLNAME, ARGINITIAL, ARGOVERFLOW) \
        MEMORY_POOL_GLUE_WITHOUT_GCMP(ARGCLASS) \
        GCMP_CREATE(ARGCLASS, ARGPOOLNAME, ARGINITIAL, ARGOVERFLOW)

#define MEMORY_POOL_GLUE_WITH_USERLOOKUP_CREATE(ARGCLASS, ARGPOOLNAME) \
        MEMORY_POOL_GLUE_WITHOUT_GCMP(ARGCLASS) \
        GCMP_CREATE(ARGCLASS, ARGPOOLNAME, -1, -1)

#define MEMORY_POOL_GLUE_ABC(ARGCLASS) \
protected: \
        virtual ~ARGCLASS(); \
public: \
        enum ARGCLASS##MagicEnum { ARGCLASS##_GLUE_NOT_IMPLEMENTED = 0 }; \
protected: \
        inline void *operator new(size_t s, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) { \
                DEBUG_CRASH(("this should be impossible to call (abstract base class)")); \
                DEBUG_ASSERTCRASH(s == sizeof(ARGCLASS), ("The wrong operator new is being called")); \
                throw ERROR_BUG; \
                return 0; \
        } \
protected: \
        inline void operator delete(void *p, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) { \
                DEBUG_CRASH(("this should be impossible to call (abstract base class)")); \
        } \
protected: \
        inline void *operator new(size_t s) { \
                DEBUG_CRASH(("this should be impossible to call (abstract base class)")); \
                DEBUG_ASSERTCRASH(s == sizeof(ARGCLASS), ("The wrong operator new is being called")); \
                throw ERROR_BUG; \
                return 0; \
        } \
        inline void operator delete(void *p) { \
                DEBUG_CRASH(("this should be impossible to call (abstract base class)")); \
        } \
private: \
        virtual MemoryPool *getObjectMemoryPool() { \
                throw ERROR_BUG; \
                return 0; \
        } \
public:

#define MEMORY_POOL_DELETEINSTANCE_VISIBILITY(ARGVIS)\
ARGVIS: void deleteInstance() { MemoryPoolObject::deleteInstance(); } public:

class MemoryPoolObject {
protected:
        virtual ~MemoryPoolObject() { }
protected:
        inline void *operator new(size_t s) { DEBUG_CRASH(("This should be impossible")); return 0; }
        inline void operator delete(void *p) { DEBUG_CRASH(("This should be impossible")); }
protected:
        virtual MemoryPool *getObjectMemoryPool() = 0;
public:
        void deleteInstance() {
                if (this) {
                        MemoryPool *pool = this->getObjectMemoryPool();
                        this->~MemoryPoolObject();
                        pool->freeBlock((void *)this);
                }
        }
};

class MemoryPoolObjectHolder {
private:
        MemoryPoolObject *m_mpo;
public:
        MemoryPoolObjectHolder(MemoryPoolObject *mpo = NULL) : m_mpo(mpo) { }
        void hold(MemoryPoolObject *mpo) { DEBUG_ASSERTCRASH(!m_mpo, ("already holding")); m_mpo = mpo; }
        void release() { m_mpo = NULL; }
        ~MemoryPoolObjectHolder() { m_mpo->deleteInstance(); }
};

inline MemoryPoolFactory *MemoryPool::getOwningFactory() { return m_factory; }
inline MemoryPool *MemoryPool::getNextPoolInList() { return m_nextPoolInFactory; }
inline const char *MemoryPool::getPoolName() { return m_poolName; }
inline Int MemoryPool::getAllocationSize() { return m_allocationSize; }
inline Int MemoryPool::getFreeBlockCount() { return getTotalBlockCount() - getUsedBlockCount(); }
inline Int MemoryPool::getUsedBlockCount() { return m_usedBlocksInPool; }
inline Int MemoryPool::getTotalBlockCount() { return m_totalBlocksInPool; }
inline Int MemoryPool::getPeakBlockCount() { return m_peakUsedBlocksInPool; }
inline Int MemoryPool::getInitialBlockCount() { return m_initialAllocationCount; }

inline DynamicMemoryAllocator *DynamicMemoryAllocator::getNextDmaInList() { return m_nextDmaInFactory; }

extern void initMemoryManager();
extern Bool isMemoryManagerOfficiallyInited();
extern void shutdownMemoryManager();

extern MemoryPoolFactory *TheMemoryPoolFactory;
extern DynamicMemoryAllocator *TheDynamicMemoryAllocator;

extern void userMemoryManagerGetDmaParms(Int *numSubPools, const PoolInitRec **pParms);
extern void userMemoryManagerInitPools();
extern void userMemoryAdjustPoolSize(const char *poolName, Int& initialAllocationCount, Int& overflowAllocationCount);

#ifdef __cplusplus
        extern void * __cdecl operator new(size_t size);
        extern void __cdecl operator delete(void *p);
        extern void * __cdecl operator new[](size_t size);
        extern void __cdecl operator delete[](void *p);
        extern void* __cdecl operator new(size_t nSize, const char *, int);
        extern void __cdecl operator delete(void *, const char *, int);
        extern void* __cdecl operator new[](size_t nSize, const char *, int);
        extern void __cdecl operator delete[](void *, const char *, int);
        inline void* __cdecl operator new[](size_t s, void *p) { return p; }
        inline void __cdecl operator delete[](void *, void *p) { }

        #ifdef MEMORYPOOL_DEBUG_CUSTOM_NEW
                #define MSGNEW(MSG)             new(MSG, 0)
                #define NEW                                             new(__FILE__, __LINE__)
        #else
                #define MSGNEW(MSG)             new
                #define NEW                                             new
        #endif
#endif

class STLSpecialAlloc {
public:
        static void* allocate(size_t __n);
        static void deallocate(void* __p, size_t);
};

#define EMPTY_DTOR(CLASS) virtual inline CLASS::~CLASS() { }

#endif
