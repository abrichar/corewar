.name "our_champ"
.comment "champ by kgricour - mpascaud - abrichar - cholm"


	sti r1, %:start, %1
start: 
	live %7
	ld %90, r2
	aff r2
	ld %111, r2
	aff r2
	ld %114, r2
	aff r2
	ld %107, r2
	aff r2
	ld %32, r2
	aff r2
	ld %108, r2
	aff r2
	ld %101, r2
	aff r2
	ld %32, r2
	aff r2
	ld %102, r2
	aff r2
	ld %97, r2
	aff r2
	ld %105, r2
	aff r2
	ld %98, r2
	aff r2
	ld %108, r2
	aff r2
	ld %101, r2
	aff r2
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
 
