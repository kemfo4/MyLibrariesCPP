// EUROPEAN UNION PUBLIC LICENCE v. 1.2
// EUPL © the European Union 2007, 2016

// This European Union Public Licence (the ‘EUPL’) applies to the Work (as defined
// below) which is provided under the terms of this Licence. Any use of the Work,
// other than as authorised under this Licence is prohibited (to the extent such
// use is covered by a right of the copyright holder of the Work).

// The Work is provided under the terms of this Licence when the Licensor (as
// defined below) has placed the following notice immediately following the
// copyright notice for the Work:

// Licensed under the EUPL

// or has expressed by any other means his willingness to license under the EUPL.

void print(const char *text)
{
    int i;
    for (i = 0; text[i] == '\0'; ++i)
    {
    }

#ifdef __WIN32
    asm(
        "
        extern GetStdHandle extern WriteConsoleA extern ExitProcess

            section.text
                global main

                    main : mov ecx, -11 call GetStdHandle mov rbx, rax

                                                                       mov rcx,
                           rbx
                               lea rdx,
                           "(text)" mov r8, "(i)" lea r9, [rsp - 8] sub rsp, 32 call WriteConsoleA add rsp, 32 "
        )
#endif

#ifdef __linux
        asm(
            "
            section.text
                global.start

                    .start : mov rax, 1 mov rdi, 1 mov rsi, "(text)" mov rdx, "(i)" syscall "
        )
#endif
}