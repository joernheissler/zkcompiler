/* maximum value of size_t */
#define MAX_SIZE ((size_t)-1)

/* assert that `a' is true. If it's false, output a description of the problem and exit
 * if `a' is false, there is a BUG in the program. Don't use for erroneous input, malloc
 * problems or similar */
#define ASSERT(a) my_assert(__FILE__, __LINE__, !(a), #a)

/* allocate count items to dst, returns 0 on error */
#define MALLOC(dst, count) ((dst) = my_malloc(sizeof *(dst), (count)), !!(dst))

/* reallocate dst to count items using temp variable tmp of same type as dst, returns 0 on error
 * contains some sanity checks to make sure that the parameters are valid
 * if reallocation fails, dst is unchanged. */
#define REALLOC(dst, tmp, count) ( \
            ASSERT(sizeof *(dst) == sizeof *(tmp)), \
            ASSERT(sizeof (dst) == sizeof (tmp)), \
            ASSERT(&(dst) != &(tmp)), \
            (tmp) = my_realloc((dst), sizeof *(dst), (count)), \
            (tmp) && ((dst) = (tmp)))

static void my_assert(char *file, unsigned line, int cond, char *str)
{
    if(!cond) return;
    fprintf(stderr, "%s:%u Assertion failed: %s\n", file, line, str);
    abort();
}

static void *my_malloc(size_t size, size_t count)
{
    void *dst;
    /* check for unsigned integer overflow */
    ASSERT(count <= MAX_SIZE / size);
    if(dst = malloc(size * count), !dst) {
        perror("malloc");
        return 0;
    }
    return dst;
}

static void *my_realloc(void *src, size_t size, size_t count)
{
    void *dst;
    /* check for unsigned integer overflow */
    ASSERT(count <= MAX_SIZE / size);
    if(dst = realloc(src, size * count), !dst) {
        perror("realloc");
        return 0;
    }
    return dst;
}

/* duplicate a string. if src is 0, return 0, else pointer to the new string. on error return 0 */
static char *my_strdup(char *src)
{
    char *dst;
    size_t l;

    if(!src) return 0;

    l = strlen(src) + 1u;
    if(!MALLOC(dst, l)) return 0;
    memcpy(dst, src, l);

    return dst;
}
