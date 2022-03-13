%macro kernel 1-*
%if %0 > 1
								push ebx
	%if %0 > 4
								push esi
								push edi
	%endif
%endif
%rep %0
	%rotate -1
								push dword %1
%endrep
								pop eax
%if %0 > 1
								pop ebx
	%if %0 > 2
								pop ecx
		%if %0 > 3
								pop edx
			%if %0 > 4
								pop esi
				%if %0 > 5
								pop edi
					%if %0 > 6
						%error "Can't do Linux syscall with 6+ params"
					%endif
				%endif
			%endif
		%endif
	%endif
%endif
								int 80h
								mov ecx, eax
								and ecx, 0fffff000h
								cmp ecx, 0fffff000h
								jne %%ok
								mov ecx, eax
								neg ecx
								mov eax, -1
								jmp short %%q
%%ok:							xor ecx, ecx
%%q:
%if %0 > 1
	%if %0 > 4
								pop edi
								pop esi
	%endif
								pop ebx
%endif
%endmacro