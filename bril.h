#ifndef BRIL_H
#define BRIL_H

void initialize_bril();

void finalize_bril();

void add_function_arg(const char *name, const char *type);

void finalize_function_args();

void add_variable(const char *name, const char *type);

void add_assignment(const char *name, const char *value, const char *type);

void add_arithmetic_operation(const char *left, const char *op, const char *right, const char *result);

void add_print(const char *value);

void add_if_condition(const char *cond, const char *true_label, const char *false_label);

void add_if_body(const char *label);

void add_end_if(const char *label);

void add_while_condition(const char *cond, const char *body_label, const char *end_label);

void add_while_body(const char *label);

void add_end_while(const char *label);

const char *convert_type(const char *type);

void add_const_assignment(const char *name, const char *type, const char *value);

void add_string_print(const char *str);

void add_conditional(const char *left, const char *op, const char *right, const char *result);

const char *convert_type(const char *type);

#endif 