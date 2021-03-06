#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>
#include <pwd.h>
#include <setjmp.h>
#include <stdarg.h>

using namespace std;

#ifndef _Nonnull
#define _Nonnull
#endif

void c3_p6()
{
    int x = 10;
    int y = 1;
    while (0 < x)
    {
        y *= x;
        x -= 1;
    }
}

void c4_p4()
{
    int x = 10;
    int y = 1;
    int z;
    if (x < y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
    printf("%d\n", z);
}

void c4_p14()
{
    int sum = 0;
    int i = 1;
    while (i < 11)
    {
        sum += i;
        i++;
    }
    printf("%d\n%d\n", sum, i);
}

void c5_p2()
{
    char buf[10];
    int i = 0;
    while (i < 20)
    {
        buf[i] = i;
        i = i + 1;
    }
}

void c5_p3()
{
    char *strings[] = {"One", "Two", "Three"};
    char *s = NULL;
    int i;
    for (i = 0; i < 3; i++)
    {
        s = strings[i];
        printf("%s\n", s);
    }
    printf("%d\n", i);
}

void c5_p15()
{
    int a, b, *p;
    p = NULL;
    if (rand())
        p = &a;
    if (p)
        *p = 42;
}

void c6_p2()
{
    int A[4][8] = {8};
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            sum += A[i][j];
        }
    }
    printf("%d\n", sum);
}

void core_CallAndMessage_helper(int x)
{
    x++;
    printf("%d\n", x);
}

// Not working
void core_CallAndMessage()
{
    int x;
    core_CallAndMessage_helper(x);
    void (*foo)() = NULL;
    foo();
}

void core_DivideZero()
{
    int x = 3;
    int y = 1;
    y--;
    printf("%d\n", x / y);
}

__attribute__((__nonnull__)) void core_NonNullParamChecker_helper(char *x)
{
    printf("%s\n", x);
}

void core_NonNullParamChecker()
{
    core_NonNullParamChecker_helper(NULL);
}

void core_NullDereference()
{
    int *x = NULL;
    printf("%d\n", *x);
}

int *core_StackAddressEscape_helper()
{
    int x = 4;
    return &x;
}

void core_StackAddressEscape()
{
    printf("%d\n", *core_StackAddressEscape_helper());
}

void core_UndefinedBinaryOperatorResult()
{
    int x = 11 << 88;
    printf("%d\n", x);
}

void core_VLASize()
{
    int n = 0;
    int v[n];
}

void core_uninitialized_ArraySubscript()
{
    int i;
    int v[] = {1, 2, 3};
    printf("%d\n", v[i]);
}

void core_uninitialized_Assign()
{
    int x, y;
    x = y;
    printf("%d\n", x);
}

void core_uninitialized_Branch()
{
    int x;
    if (x)
    {
        x = 4;
    }
    else
    {
        x = -3;
    }
    printf("%d\n", x);
}

void core_uninitialized_CapturedBlockVariable()
{
    int x;
    for (int i = 0; i < 3; ++i)
    {
        x++;
    }
    printf("%d\n", x);
}

int core_uninitialized_UndefReturn()
{
    int x;
    return x;
}

void cplusplus_InnerPointer()
{
    string s = "llvm";
    const char *c = s.data();
    s = "clang";
    printf("%s\n", c);
}

// Not working
void cplusplus_Move()
{
    string str = "Hello, world!\n";
    vector<string> messages;
    #ifdef APPLE
    messages.__emplace_back(move(str));
    #else
    messages.emplace_back(move(str));
    #endif
    cout << str;
}

void cplusplus_NewDelete()
{
    int *x = new int;
    *x = 4;
    delete x;
    // delete x;
    printf("%d\n", x);
}

void cplusplus_NewDeleteLeaks()
{
    int *x = new int;
    *x = 4;
}

class cplusplus_PureVirtualCall
{
public:
    virtual void dummy() = 0;
    cplusplus_PureVirtualCall()
    {
        dummy();
    }
};

void deadcode_DeadStores()
{
    int x = 4;
    int y = x + 3;
}

void nullability_NullPassedToNonnull_helper(_Nonnull int *x)
{
    printf("%d\n", *x);
}

void nullability_NullPassedToNonnull()
{
    int *x = NULL;
    nullability_NullPassedToNonnull_helper(x);
}

// Not working
_Nonnull int *nullability_NullReturnedFromNonnull()
{
    int *x = NULL;
    return x;
}

void security_FloatLoopCounter()
{
    float i;
    for (i = 0; i < 100; i++)
    {
        printf("%d\n", (int)i);
    }
}

// Not working?
void security_insecureAPI_DeprecatedOrUnsafeBufferHandling()
{
    int x = atoi("1");
    printf("%d\n", x);
}

// Not working
void security_insecureAPI_UncheckedReturn()
{
    char s[100];
    int fd = open("/tmp/aaaaaaa.txt", O_RDWR);
    read(fd, s, 100);
}

void security_insecureAPI_bcmp()
{
    bcmp("123", "abc", 3);
}

void security_insecureAPI_bcopy()
{
    char x[2];
    bcopy(x, (void *)"abc", 3);
}

void security_insecureAPI_bzero()
{
    char x[2];
    bzero(x, 3);
}

#ifdef APPLE
void security_insecureAPI_gets()
{
    char s[10];
    gets(s);
}
#endif

void security_insecureAPI_mkstemp()
{
    mkstemp("/tmp/a.XX");
}

void security_insecureAPI_mktemp()
{
    mktemp("/tmp/a.XX");
}

void security_insecureAPI_rand()
{
    int key = rand();
    int x = 8;
    printf("%d\n", x ^ key);
}

void security_insecureAPI_strcpy()
{
    char s1[4];
    char s2[] = "12345";
    char *sp1 = s1;
    char *sp2 = s2;
    strcpy(sp1, sp2);
}

void security_insecureAPI_vfork()
{
    int pid;
    if ((pid = vfork()) == 0)
    {
        execl("/bin/ls", "/bin/ls");
        _exit(1);
    }
}

#ifndef APPLE
void security_insecureAPI_getpw(uid_t uid, char *buf)
{
    getpw(uid, buf);
}
#endif

// Not working
class optin_cplusplus_UninitializedObject
{
private:
    int x;
    int *z;
} optin_cplusplus_UninitializedObject_obj;

class optin_cplusplus_VirtualCall
{
public:
    virtual void dummy() {}
    optin_cplusplus_VirtualCall()
    {
        dummy();
    }
};

// Not working
struct optin_performance_Padding
{
    char a;
    int b;
    double c;
    char d;
    double f;
};

void valist_CopyToSelf(int x, ...)
{
    va_list arguments;
    va_start(arguments, x);
    va_copy(arguments, arguments);
    va_end(arguments);
}

void valist_Unterminated(int x, ...)
{
    va_list arguments;
    va_start(arguments, x);
}

// Not working?
void unix_API()
{
    jmp_buf jmp_buf;
    int ret;
    ret = setjmp(jmp_buf);
    if (0 == ret)
    {
        longjmp(NULL, 1);
    }
}

void unix_Malloc()
{
    char *p = (char *)malloc(8);
    char *leak = (char *)malloc(8);

    /* Double free */
    free(p);
    free(p);

    /* Use after free */
    leak[1] = p[1];
}

void unix_MallocSizeof()
{
    char *p;
    char *sp;
    char s[] = "0123456789";

    sp = s;
    p = (char *)malloc(sizeof(sp));
    strcpy(p, sp);
    free(p);
}

// Not working?
void unix_cstring_BadSizeArg()
{
    char src[] = "1234";
    char dest[10];
    char *src_p = src;

    strncpy(dest, src_p, sizeof(src_p));
}

void unix_cstring_NullArg()
{
    char dest[80];
    char src[] = "123";
    char *p = NULL;

    strncpy(dest, p, 80);
}

void valist_Uninitialized(void *arg0, ...)
{
    va_list va;
    int integer;
    integer = va_arg(va, int);
    va_end(va);
}

int main()
{
    c3_p6();
    c4_p4();
    c4_p14();
    c5_p2();
    c5_p3();
    c5_p15();
    c6_p2();
    return 0;
}
