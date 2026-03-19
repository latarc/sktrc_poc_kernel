#undef TRACE_SYSTEM
#define TRACE_SYSTEM poc_ets

#if !defined(_TRACE_POC_ETS_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_POC_ETS_H

#include <linux/tracepoint.h>

TRACE_EVENT(poc,
	TP_PROTO(int a, int b),
	TP_ARGS(a, b),
	TP_STRUCT__entry(
		__field(int, a)
		__field(int, b)
	),
	TP_fast_assign(
		__entry->a = a;
		__entry->b = b;
	),
	TP_printk("The result of %d + %d is%s equal to 5.",
		__entry->a, __entry->b, ((__entry->a + __entry->b) == 5) ? "" : "n't")
	);

TRACE_EVENT(sum,
	TP_PROTO(int res, int a, int b),
	TP_ARGS(res, a, b),
	TP_STRUCT__entry(
		__field(int, res)
		__field(int, a)
		__field(int, b)
	),
	TP_fast_assign(
		__entry->res = res;
		__entry->a = a;
		__entry->b = b;
	),
	TP_printk("res = a + b => %d = %d + %d",
		__entry->res, __entry->a, __entry->b)
	);

#endif /* _TRACE_POC_ETS_H */

/* This part must be outside protection */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#define TRACE_INCLUDE_FILE poc_ets
#include <trace/define_trace.h>
