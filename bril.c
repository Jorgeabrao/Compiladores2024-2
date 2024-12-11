#include "bril_generator.h"
#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static FILE *bril_file = NULL;
static int label_counter = 0;

void initialize_bril() {
    bril_file = fopen("output.bril", "w");
    if (!bril_file) {
        fprintf(stderr, "Não foi possível criar o arquivo output.bril\n");
        exit(1);
    }
    fprintf(bril_file, "@main");
}

void finalize_bril() {
    if (bril_file) {
        fprintf(bril_file, "\n}\n");
        fclose(bril_file);
        bril_file = NULL;
    }
}

void add_function_arg(const char *name, const char *type) {
    if (bril_file) {
        static int first = 1;
        if (first) {
            fprintf(bril_file, "(%s: %s", name, type);
            first = 0;
        } else {
            fprintf(bril_file, ", %s: %s", name, type);
        }
    }
}

void finalize_function_args() {
    if (bril_file) {
        fprintf(bril_file, ") {\n");
    }
}

void add_variable(const char *name, const char *type) {
    if (bril_file) {
        fprintf(bril_file, "  %s: %s = const 0;\n", name, type);  // Inicialização padrão
    }
}

void add_const_assignment(const char *name, const char *type, const char *value) {
    if (bril_file) {
        if (strcmp(type, "literal") == 0) {
            fprintf(bril_file, "  %s: %s = const '%s';\n", name, convert_type(type), value);
        } else if (strcmp(type, "inteiro") == 0 || strcmp(type, "real") == 0) {
            fprintf(bril_file, "  %s: %s = const %s;\n", name, convert_type(type), value);
        } else {
            fprintf(bril_file, "  %s: %s = const %s;\n", name, convert_type(type), value);
        }
    }
}

void add_arithmetic_operation(const char *left, const char *op, const char *right, const char *result) {
    const char *bril_op;
    if (strcmp(op, "+") == 0) bril_op = "add";
    else if (strcmp(op, "-") == 0) bril_op = "sub";
    else if (strcmp(op, "*") == 0) bril_op = "mul";
    else if (strcmp(op, "/") == 0) bril_op = "div";
    else {
        fprintf(stderr, "Operador desconhecido: %s\n", op);
        return;
    }
    if (bril_file) {
        fprintf(bril_file, "  %s = %s %s %s;\n", result, bril_op, left, right);
    }
}

void add_print(const char *value) {
    if (bril_file) {
        fprintf(bril_file, "  print %s;\n", value);
    }
}

void add_string_print(const char *value) {
    if (bril_file) {
        size_t len = strlen(value);
        for (size_t i = 0; i < len; i++) {
            fprintf(bril_file, "  l%zu: char = const '%c';\n", i, value[i]);
        }
        fprintf(bril_file, "  print");
        for (size_t i = 0; i < len; i++) {
            fprintf(bril_file, " l%zu", i);
        }
        fprintf(bril_file, ";\n");
    }
}

void add_if_condition(const char *cond, const char *true_label, const char *false_label) {
    if (bril_file) {
        fprintf(bril_file, "  br %s .%s .%s;\n", cond, true_label, false_label);
    }
}

void add_if_body(const char *label) {
    if (bril_file) {
        fprintf(bril_file, "  .%s:\n", label);
    }
}

void add_end_if(const char *label) {
    if (bril_file) {
        fprintf(bril_file, "  .%s:\n", label);
    }
}

void add_while_condition(const char *cond, const char *body_label, const char *end_label) {
    if (bril_file) {
        fprintf(bril_file, "  br %s .%s .%s;\n", cond, body_label, end_label);
    }
}

void add_while_body(const char *label) {
    if (bril_file) {
        fprintf(bril_file, "  .%s:\n", label);
    }
}

void add_end_while(const char *label) {
    if (bril_file) {
        fprintf(bril_file, "  jmp .%s;\n", label);
        fprintf(bril_file, "  .%s:\n", label);
    }
}

void add_conditional(const char *left, const char *op, const char *right, const char *result) {
    const char *bril_op;
    if (strcmp(op, "==") == 0) bril_op = "ceq";
    else if (strcmp(op, "<") == 0) bril_op = "lt";
    else if (strcmp(op, ">") == 0) bril_op = "gt";
    else if (strcmp(op, "<=") == 0) bril_op = "le";
    else if (strcmp(op, ">=") == 0) bril_op = "ge";
    else {
        fprintf(stderr, "Operador relacional desconhecido: %s\n", op);
        return;
    }
    if (bril_file) {
        fprintf(bril_file, "  %s: bool = %s %s %s;\n", result, bril_op, left, right);
    }
}

const char *convert_type(const char *type) {
    if (strcmp(type, "literal") == 0) return "char";
    if (strcmp(type, "inteiro") == 0) return "int";
    if (strcmp(type, "real") == 0) return "float";
    return "unknown";
}