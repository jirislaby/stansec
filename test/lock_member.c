extern void __st_mutex_lock_st__(int *);
extern void __st_mutex_unlock_st__(int *);

struct str {
	int lock;
	int *lockP;
};

void fun_correct1(struct str *str1)
{
	__st_mutex_lock_st__(&str1->lock);
	__st_mutex_unlock_st__(&str1->lock);
}

void fun_correct2(struct str *str2)
{
	__st_mutex_lock_st__(str2->lockP);
	__st_mutex_unlock_st__(str2->lockP);
}
