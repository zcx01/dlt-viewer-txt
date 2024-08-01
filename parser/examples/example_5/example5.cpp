#include "example5.h"

#include "dlt_id.h"

DLT_DECLARE_CONTEXT(DLTtest1);
DLT_DECLARE_CONTEXT(DLTtest2);
DLT_DECLARE_CONTEXT(DLTtest3);
DLT_DECLARE_CONTEXT(DLTtest4);

void example5_init()
{
    dlt_user_init();

    DLT_REGISTER_APP("ALOG","Test Application for Logging");
    DLT_REGISTER_CONTEXT_APP(DLTtest1,"TES1","ALOG","Test Context for Logging");
    DLT_REGISTER_CONTEXT_APP(DLTtest2,"TES2","ALOG","Test 2 Context for Logging");
    DLT_REGISTER_CONTEXT_APP(DLTtest3,"TES3","ALOG","Test 3 Context for Logging");
    DLT_REGISTER_CONTEXT_APP(DLTtest4,"TES4","ALOG","Test 4 Context for Logging");

    DLT_LOG1(DLTtest1,DLT_LOG_INFO,DLT_STRING("Hello BMW"));
}

void example5_test1()
{
    const char data[] = "Hello world";

    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_UINT8(255));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_UINT16(65535));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_UINT32(4294967295));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_UINT64(18446744073709551615));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_INT8(-128));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_INT16(-32768));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_INT32(-2147483648));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_INT64(-9223372036854775808));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_INT(109));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_UINT(110));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_BOOL(111));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_STRING("STRING 112 message"));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_CSTRING("CSTRING 113 message"));
    DLT_LOG3(DLTtest2,DLT_LOG_INFO,DLT_CSTRING("Foo"),DLT_INT(1),DLT_CSTRING("bar"));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_FLOAT32(1.1));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_FLOAT64(1.2));
    DLT_LOG1(DLTtest2,DLT_LOG_INFO,DLT_RAW((void*)data,sizeof(data)));
}

void example5_test2()
{
    DLT_LOG0(DLTtest3,DLT_LOG_INFO);
    DLT_LOG1(DLTtest3,DLT_LOG_INFO,DLT_INT(21));
    DLT_LOG2(DLTtest3,DLT_LOG_INFO,DLT_INT(31),DLT_INT(32));
    DLT_LOG3(DLTtest3,DLT_LOG_INFO,DLT_INT(41),DLT_INT(42),DLT_INT(43));
    DLT_LOG4(DLTtest3,DLT_LOG_INFO,DLT_INT(51),DLT_INT(52),DLT_INT(53),DLT_INT(54));
    DLT_LOG5(DLTtest3,DLT_LOG_INFO,DLT_INT(61),DLT_INT(62),DLT_INT(63),DLT_INT(64),DLT_INT(65));
    DLT_LOG6(DLTtest3,DLT_LOG_INFO,DLT_INT(71),DLT_INT(72),DLT_INT(73),DLT_INT(74),DLT_INT(75),DLT_INT(76));
}

void example5_test3(int repeat)
{
    for(int num=0;num<repeat;num++)
        DLT_LOG2(DLTtest4,DLT_LOG_INFO,DLT_INT(num),DLT_CSTRING("Hello world! This is a very long text which must not be part of the message itself!"));
}