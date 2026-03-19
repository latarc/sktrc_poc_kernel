#include <linux/module.h>
#include <linux/init.h>

#define CREATE_TRACE_POINTS
#include "poc_ets.h"

static int sum(int a, int b)
{
	int res = a + b;
	trace_sum(res, a, b);
	return res;
}

static void poc(void)
{
	for (int i = 0; i < 5; ++i) {
		if (sum(i, i + 1) == 5) {
			trace_poc(i, i + 1);
		} else {
			trace_poc(i, i + 1);
		}
	}
	return;
}

static int __init poc_ets_init(void)
{
	poc();
	return 0;
}

static void __exit poc_ets_exit(void)
{
	return;
}

module_init(poc_ets_init);
module_exit(poc_ets_exit);

MODULE_LICENSE("GPL");
