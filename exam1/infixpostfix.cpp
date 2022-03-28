/*
Stack Applications:
	-LIFO (Last-in-First-out) Philosophy
	-Subroutines
	-Recommendation Engines
	-Memory Management Modules
	-Etc...

Postfix:
	2 + 3 = 5
	2 + 3 * 5 = ... 17 (takes longer to solve)
	
	-Computers scan lines from left-to-right...
		So, 2 + 3 * 5  =  5 * 5 .... that's not right!

	-Computers are able to do this correctly though.
		How? Program must be able to prioritize
		despite reading from left-to-right.

- - - - - - - - - - - - - - - - - - - - - - - - - - -
	-Math expressions in order are called:
			Infix Equations

	-Computer must convert these to be able to read
		them correctly. These are called:
			Postfix Equations
		(Operations after the expression)
		(Captures the desired order of operations)
- - - - - - - - - - - - - - - - - - - - - - - - - - -

	Infix				Postfix
	a + b		=>		ab+
	a + b * c	=>		abc*+
	
	-Stack can be used to convert infix to postfix.
		// Remember PEMDAS!

	Problem:
		Input:	a+b*c
		Output:	abc*+	[Why? See below]

			// Operator affects the two operands to its left. In the above
				case, the * affects the 'b' and 'c', while the + affects
				the 'b*c' and 'a'.

	Constraints:
		-We read one symbol at a time, left to right.
		-Symbol is either an operand or operator.
		-Operands can be written directly to postfix
			 (e.g. a, b, c, d...)
		-Operators require more work...


	The Algorithm:
		1) Scan the next symbol. Terminate if NULL.
			I.E. Stop when no more symbols.
		2) If the symbol is an operand, write
			straight to postfix expression.
		3) If the symbol is an operator:
			3.1) If the precendence of the scanned
				operator is greater than the precedence
				of the operator in the stack (or if the
				stack is empty), push it.
					*Parentheses: If the symbol is a '(', push it.

			Ex:		A+B*C:	ABC*+	(+ sign is 'pushed' to make room for
										the * sign)

			3.2) Else, pop all the operators from the
				stack which are greater than or equal
				to in precedence than that of the
				scanned operator. Afterwards, push
				the scanned operator to the stack.
					*Parentheses: If the synbol is a ')', pop all operators
						until you encounter a '('. 
						[DO NOT WRITE PARENTHESES TO THE POSTFIX!!!!]

			Ex:		A*B+C:	AB*C+	(* sign is 'popped' to the expression, while
										the + sign is added at the end)

		4) Repeat steps 1-3 for all symbols. When all
			symbols are scanned, pop the contents of
			the stack onto the postscript.

			// Complicated? See examples below!


	Examples:

		Next Symbol Read	Stack Contents	 Postfix Expression
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - [Basic Core]
								NULL								1) A + B + C
				A								A
				+				+
				B								AB
				+				++
				C								ABC

					All symbols scanned, pop Stack
					to Postfix Expression...
												ABC++

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - [More Complex]
								NULL								2) A + B * C
				A								A
				+				+
				B								AB
				*				*+
				C		// + is 'pushed'		ABC
							since it has a
							lower precedence
												ABC*+
										// Seems like this implies
											A * B + C, but not quite.
											This is an expression *Tree*,
											which is a semi-complicated
											concept.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - [Flipped]
								NULL								3) A * B + C
				A								A
				*				*
				B								AB*
				+				+ -> * -----------^
				C								AB*C
								
												AB*C+

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - [A->E]
								NULL								4) A + B * C - D / E
				A								A
				+				+
				B								AB
				*				*+
				C								ABC*+
				-				- -> *+ -----------^
				D								ABC*+D
				/				/-
				E								ABC*+DE

												ABC*+DE/-
											// NOTE: In the case of A - B * C +....,
												the step between C & D would instead be:
				C								ABC*
				-				+- -> * ------------^
											// Since '-' has a lower precedence than +,
												the '*' sign is popped but the '-' sign
												is just pushed!

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - [Parentheses...]
								NULL								5) A * (B + C) / D									
				A								A									
				*				*							
				(				(*
				B								AB
				+				+(*
							// Almost creates a
								new scope. Do not
								pop the *.
				C								ABC+*
				)				)* -> +( ----------^^
						// Pop every thing between	^
							the ) and (. In this	^
							case, )+(* -> pop the	^
							 + and leave the *.		^	
				/				/ -> * -------------^
				D								ABC+*D
												>ABC+*D/
											// Note there are no
												parentheses in the 
												post-fix.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/