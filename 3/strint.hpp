#ifndef STRINT_H
#define STRINT_H

#include <iostream>
namespace lab3 {
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

            Strint& operator=(const Strint &other);
            Strint& operator=(Strint &&other) noexcept;
            friend std::ostream& operator<<(std::ostream& os, const Strint& p);

            void print_string();
            const char* get_str() const;
            const int get_int() const;

            static Strint get_random_strint();
    };
}

#endif