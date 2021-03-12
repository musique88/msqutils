#define msq_info "[INFO]"
#define msq_warn "\033[93m[WARNING]"
#define msq_erro "\033[1;31m[ERROR]"
#define msq_end "\033[0m\n"

typedef unsigned char uchar;
typedef unsigned int uint;

#define VECTOR_ADDED_CAPACITY 5

struct vector{
	void ** objects;
	uint size;
	uint capacity;
};

void v_reserve(struct vector *v, uint capacity);
void v_free(struct vector *v);
struct vector v_create(uint capacity);
struct vector v_create_from_arr(void** a, uint s);
void v_append(struct vector* v, void * o);

enum msq_malloc_flags{
	MSQ_LOG_MALLOC = 0b00000001
};

typedef uint msq_malloc_index;

struct msq_malloc_tracker{
	uchar flags;
	struct vector v;
};

void * msq_malloc(struct msq_malloc_tracker *tracker, uint size, msq_malloc_index *index);
void * msq_malloc_at(struct msq_malloc_tracker *tracker, msq_malloc_index index);
void msq_free(struct msq_malloc_tracker *tracker, msq_malloc_index index);
void msq_free_all(struct msq_malloc_tracker *tracker);
