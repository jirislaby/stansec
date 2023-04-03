extern void __st_mutex_lock_st__(int *);
extern void __st_mutex_unlock_st__(int *);

int lock;

void fun_imbalance()
{
	__st_mutex_lock_st__(&lock);
}
