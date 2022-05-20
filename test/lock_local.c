extern __st_mutex_lock_st__(int *);
extern __st_mutex_unlock_st__(int *);

void fun_correct()
{
	int lock;

	__st_mutex_lock_st__(&lock);
	__st_mutex_unlock_st__(&lock);
}
