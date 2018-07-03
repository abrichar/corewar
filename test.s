.name "test"
.comment "the test"

live %7
ld %7, r1
ld 7, r1
st r1, 7
st r1, r2
add r1, r2, r3
and r1, r2, r3
and 7, r2, r3
and %7, r2, r3
and %7, 77, r3
and %7, %77, r3
and 7, r2, r3
and 7, %77, r3
and 7, 77, r3
or r1, r2, r3
or 7, r2, r3
or %7, r2, r3
or %7, 77, r3
or %7, %77, r3
or 7, r2, r3
or 7, %77, r3
or 7, 77, r3
xor r1, r2, r3
xor 7, r2, r3
xor %7, r2, r3
xor %7, 77, r3
xor %7, %77, r3
xor 7, r2, r3
xor 7, %77, r3
xor 7, 77, r3
zjmp %42
ldi r1, r2, r3
ldi %1, r2, r3
ldi 1, %2, r3
ldi %1, %2, r3
sti r1, %7, %42
fork %77
lld %42, r1
lld 42, r1
lldi %42, r7, r1
lldi 42, %7, r1
lfork %777
aff r1

