.name "champ"
.comment "test"


start:
        ld %90, r2
        aff r2
zork:
        ld %777, r3
        zjmp %:start
        st  r4, :zork
        fork %:start
        sti r1, %:live, %1
live:
        live %7
        ld %0, r5
        fork %:live
        zjmp %:live