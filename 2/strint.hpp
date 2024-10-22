#ifndef STRINT_H
#define STRINT_H

namespace lab2 {
    class Strint {
        private:
            int num;
            char* str;
            int str_len;
        public:
            Strint();
            Strint(int num, const char *str);
            Strint(const Strint &s);
            Strint(Strint &&s);
            ~Strint();

            Strint& operator=(const Strint &&other);
            Strint& operator=(Strint &&other) noexcept;

            void print_string();
            int get_int();
    };
}

#endif