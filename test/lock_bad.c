extern void __st_mutex_lock_st__(int *);
extern void __st_mutex_unlock_st__(int *);

extern int fun(int);

void fun_imbalance(int *mA1, int B)
{
	__st_mutex_lock_st__(mA1);
	if (B)
		return;
	__st_mutex_unlock_st__(mA1);
	fun(0);
}

void fun_double(int *mA2)
{
	__st_mutex_lock_st__(mA2);
	__st_mutex_lock_st__(mA2);
	fun(0);
}
