extern __st_mutex_lock_st__(int *);
extern __st_mutex_unlock_st__(int *);

extern int fun(int);

void fun_imbalance(int *mA, int B)
{
	__st_mutex_lock_st__(mA);
	if (B)
		return;
	__st_mutex_unlock_st__(mA);
	fun(0);
}

void fun_double(int *mA)
{
	__st_mutex_lock_st__(mA);
	__st_mutex_lock_st__(mA);
	fun(0);
}
