	.name "attacker"
	.comment "L'attaque est la meilleur défense."

	fork %:live
	live %234
	fork %:attack

fork:
	live %234
    fork %:live
    ld %0, r16
    zjmp %:fork

live:
	live %234
    ld %0, r16
    zjmp %:live

attack:
	live %432
	lfork %1000
	live %432
	lfork %2000
	live %432
	lfork %3000
	live %432
	lfork %4000
	live %432
	lfork %5000
	ld %0, r16
    zjmp %:attack