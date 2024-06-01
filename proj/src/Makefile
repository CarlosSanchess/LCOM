# name of the program (Minix service)
PROG=proj

.PATH: ${.CURDIR}/dev_interface/
.PATH: ${.CURDIR}/dev_interface/devices
.PATH: ${.CURDIR}/dev_interface/devices/timer_kbc_mouse
.PATH: ${.CURDIR}/Views
.PATH: ${.CURDIR}/controllers
.PATH: ${.CURDIR}/Models

# source code files to be compiled

SRCS = main.c utils.c kbc.c mouse.c rtc.c timer.c video_gr.c views.c arena.c tank.c obstacle.c bullet.c arenaController.c mouseController.c rtcController.c enemyController.c tankController.c bulletController.c kbController.c timerController.c collisionController.c builderController.c gameController.c

# additional compilation flags
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
CFLAGS += -pedantic

# list of library dependencies (for Lab 2, only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
