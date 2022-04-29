extern __st_mutex_lock_st__(int *);
extern __st_mutex_unlock_st__(int *);

struct str {
	int lock;
	int *lockP;
};

void fun_correct1(struct str *str)
{
	__st_mutex_lock_st__(&str->lock);
	__st_mutex_unlock_st__(&str->lock);
}

void fun_correct2(struct str *str)
{
	__st_mutex_lock_st__(str->lockP);
	__st_mutex_unlock_st__(str->lockP);
}
