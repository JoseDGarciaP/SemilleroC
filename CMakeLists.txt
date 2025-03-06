cmake_minimum_required(VERSION 3.30)
project(SemilleroC C)

set(CMAKE_C_STANDARD 99)

add_executable(SemilleroC src/main.c
        src/features/services/purchase/purchase.c
        src/features/services/purchase/purchase.h
        src/features/services/closing/closing.c
        src/features/services/closing/closing.h
        src/features/services/cancellation/cancellation.c
        src/features/services/cancellation/cancellation.h
        src/features/services/report/report.c
        src/features/services/report/report.h
        src/features/services/reprint/reprint.c
        src/features/services/reprint/reprint.h
        src/features/menu/menu.c
        src/features/menu/menu.h)
