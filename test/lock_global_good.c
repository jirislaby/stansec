extern void __st_mutex_lock_st__(int *);
extern void __st_mutex_unlock_st__(int *);

int lock;

void fun_correct()
{
	__st_mutex_lock_st__(&lock);
	__st_mutex_unlock_st__(&lock);
}
