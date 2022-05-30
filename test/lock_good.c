extern __st_mutex_lock_st__(int *);
extern __st_mutex_unlock_st__(int *);

extern int fun(int);

void fun_correct1(int *mA1)
{
	__st_mutex_lock_st__(mA1);
	__st_mutex_unlock_st__(mA1);
	fun(0);
}

void fun_correct2(int *mA2)
{
	fun(0);
	__st_mutex_lock_st__(mA2);
	fun(1);
	fun(2);
	if (fun(3)) {
		fun(4);
		fun(5);
	}
	fun(6);
	__st_mutex_unlock_st__(mA2);
	fun(7);
}
