EXECS=GetHalo
CC=gcc
all:${EXECS}

ExportGalaxies:GetHalo.c
	${CC} -o GetHalo GetHalo.c
	
Clean:
	rm -f ${EXECS}
