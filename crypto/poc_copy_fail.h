#undef TRACE_SYSTEM
#define TRACE_SYSTEM poc_copy_fail

#if !defined(_TRACE_POC_COPY_FAIL_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_POC_COPY_FAIL_H

#include <linux/tracepoint.h>

TRACE_EVENT(overwriting,
	TP_PROTO(struct scatterlist *addr, u64 data),
	TP_ARGS(addr, data),
	TP_STRUCT__entry(
		__field(struct scatterlist*, addr)
		__field(u64, data)
	),
	TP_fast_assign(
		__entry->addr = addr;
		__entry->data = data;
	),
	TP_printk("Overwriting data at address %016llx (0x%016llx)",
		__entry->addr, __entry->data)
	);

TRACE_EVENT(loaded,
	TP_PROTO(int required),
	TP_ARGS(required),
	TP_STRUCT__entry(
		__field(int, required)
	),
	TP_fast_assign(
		__entry->required = required;
	),
	TP_printk("Instrumented module loaded for controlled analysis.%s",
		__entry->required ? "" : "")
	);

TRACE_EVENT(receiving,
	TP_PROTO(int required),
	TP_ARGS(required),
	TP_STRUCT__entry(
		__field(int, required)
	),
	TP_fast_assign(
		__entry->required = required;
	),
	TP_printk("Receiving payload fragment...%s",
		__entry->required ? "" : "")
	);

#endif /* _TRACE_POC_COPY_FAIL_H */

/* This part must be outside protection */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#define TRACE_INCLUDE_FILE poc_copy_fail
#include <trace/define_trace.h>
