.name "our_champ"
.comment "champ by kgricour - mpascaud - abrichar - cholm"


erase1:
	    sti r1, %:live1, %1
erase2:
	    sti r1, %:live2, %1
erase3:
	    sti r1, %:live3, %1
erase4:
	    sti r1, %:live4, %1
erase5:
	    sti r1, %:live5, %1
erase6:
	    sti r1, %:live6, %1
erase7:
	    sti r1, %:live7, %1
erase8:
	    sti r1, %:live8, %1
erase9:
	    sti r1, %:live9, %1
live1:
	    live %7
live2:
	    live %7
live3:
	    live %7
live4:
	    live %7
live5:
	    live %7
live6:
	    live %7
live7:
	    live %7
live8:
	    live %7
live9:
	    st r2, :erase1
	    st r2, :erase2
	    st r2, :erase3
	    st r2, :erase4
	    st r2, :erase5
	    st r2, :erase6
	    st r2, :erase7
	    st r2, :erase8
	    st r2, :erase9
start:
zork:
	    ld %777, r3
	    zjmp %:start
	    st  r4, -8
	    fork %:start
	    sti r1, %:live, %1
live:
	    live %7
	    ld %0, r5
	    fork %:live
	    ld %777, r3
	    zjmp %:live
	    st  r4, -8
	    live %7
	    fork %:live
	    ld %57672960, r5
	    ld %201392128, r6
	    sti r5, %50, %50
	    sti r6, %50, %47