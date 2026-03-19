#include <linux/module.h>
#include <linux/init.h>

#include <trace/sktrc.h>
#define ID 1

static int sum(int a, int b)
{
	int res = a + b;
	sktrc(SKTRC_HASH(0, 0, ID, 2),
			"res = a + b => %d = %d + %d",
			res, a, b);
	return res;
}

static void poc(void)
{
	for (int i = 0; i < 5; ++i) {
		if (sum(i, i + 1) == 5) {
			sktrc(SKTRC_HASH(0, 1, ID, 1),
					"The result of %d + %d is equal to 5, yay!",
					i, i + 1);
		} else {
			sktrc(SKTRC_HASH(0, 2, ID, 1),
					"Oops, the result of %d + %d isn't equal to 5.",
					i, i + 1);
		}
	}
	return;
}

static int __init poc_sktrc_init(void)
{
	poc();
	return 0;
}

static void __exit poc_sktrc_exit(void)
{
	return;
}

module_init(poc_sktrc_init);
module_exit(poc_sktrc_exit);

MODULE_LICENSE("GPL");
