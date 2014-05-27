"simple0" format {#format_simple0_page}
================

\section format_simple0_specifications_sec Specifications

\subsection format_simple0_directory_tree_ssec Directory tree
Problem in "simple0" is a folder with the following entries:

- *config.ini* -- \ref format_simple0_configuration_file_ssec
- *checker/* -- directory with \ref checker_page
- *statement/* -- directory with \ref statement_page
- *tests/* -- directory with tests
    - Each test is set of files which names has "test_id.data_id" format
    - Data set of test is set of data_ids
    - Data set must be equal to ``{'in'}`` or ``{'in', 'out'}``.
    - Data sets are equal among different tests
    - Each test file is considered to be either *text* or *binary*
        - File is considered to be *binary* if it is specified in section "[tests]" from config.ini
        - File is considered to be *text* if it is specified in section "[tests]" from config.ini
        - File is considered to be *text* if it is not specified

\subsection format_simple0_testing_algorithm_ssec Testing algorithm

1. Solution testing is performed on all tests.
2. Test order is numeric if all test_ids match pattern ``'\d+'`` otherwise order is lexicographical.
3. Testing algorithm is *WHILE_NOT_FAIL*.
4. Solution is executed on specified test.
5. After solution execution checker is executed.

\subsection format_simple0_configuration_file_ssec Configuration file

\subsubsection format_simple0_specifications_sssec Specifications
- It has \ref ini_page
- It has "utf8" encoding
- It is divied into several sections
    - **info** section has the following options
        - name -- the name of the problem
        - authors -- the list of authors separated by spaces, see \ref format_simple0_username_sssec
        - maintainers -- the list of maintainers separated by spaces, see \ref format_simple0_username_sssec
        - source -- the source of the problem (contest name, championship...)
    - **resource_limits** section has the following options
        - *memory* -- \ref format_simple0_fixed_point_decimal_sssec, see \ref format_simple0_memory_value_par
        - *time* --  \ref format_simple0_fixed_point_decimal_sssec, see \ref format_simple0_time_value_par
        - *output* -- \ref format_simple0_fixed_point_decimal_sssec, see \ref format_simple0_memory_value_par
        - *real_time* --  \ref format_simple0_fixed_point_decimal_sssec, see \ref format_simple0_time_value_par
    - **files** section has following options: *stdin*, *stdout*, *stderr*.
        - Solution can use up to 3 files corresponding to *stdin*, *stdout* and *stderr* data streams.
        - File ids are *stdin*, *stdout*, *stderr*.
        - File with *stdin* id is filled from test file with ``data_id=in``.
        - *stdout* and *stderr* may be filled by solution.
        - If option is present no redirections are introduced for file id.
        - If option is not present file redirection is introduced
          and file name is unspecified.
    - **tests** section describes data set of the tests.
      You can specify file format of the data_id.
      ``data_id`` is one of *in* or *out*.
        - ``data_id = text`` -- for text files
        - ``data_id = binary`` -- for binary files

\subsubsection format_simple0_username_sssec Username

Username is used by BACS.WEB.

Username is non-empty string matching the following regular expression: ``^[a-zA-Z0-9_-]+$``.


\subsubsection format_simple0_fixed_point_decimal_sssec Fixed point decimal

Values in configuration files are fixed point decimals
with optional multiple suffix.

Values is defined corresponding to EBNF below.
"multiple unit" non-terminal is defined for specified value types.

Si multiples give \f$10^k\f$ multiplier.
Si submultiples give \f$10^{-k}\f$ multiplier.
Binary multiples give \f$2^{10k}\f$ multiplier.


\code{none}
value = decimal, multiple unit ;
decimal = unsigned, [dot, unsigned] ;
dot = "." ;
unsigned = digit, {digit} ;
digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;

no multiple = "" ;
si multiple = "da" | "h" | "k" | "M" | "G" | "T" | "P" | "E" | "Z" | "Y" ;
si submultiple = "d" | "c" | "m" | "u" | "n" | "p" | "f" | "a" | "z" | "y" ;
binary multiple = "Ki" | "Mi" | "Gi" | "Ti" | "Pi" | "Ei" | "Zi" | "Yi" ;
\endcode

\paragraph format_simple0_memory_value_par Memory value

\code{none}
multiple unit = "" | (multiple, unit) ;
multiple = si multiple | binary multiple | no multiple ;
unit = "B" ;
\endcode

\paragraph format_simple0_time_value_par Time value

\code{none}
multiple unit = "" | (multiple, unit) ;
multiple = si multiple | si submultiple | no multiple ;
unit = "s" ;
\endcode

\subsubsection format_simple0_examples_sssec Examples

\paragraph format_simple0_complicated_sample_par Complicated sample

\code{.ini}
[info]
; It is comment
name = Problem name

; Problem is created by "author1" and "author2"
authors = author1 author2

; Here you can specify user names/ids (related to BACS.WEB)
;
; Note that names will be trimmed, so here the following string list is specified:
; ["admin", "contest_admin"]
maintainers = admin contest_admin

source = PTZ summer 2011

[resource_limits]
memory = 256MiB
; 1 second
time = 1s

[files]
; Note that stdin is not specified, so it is redirected from "in" file from test
; stdout will not be redirected
; stderr is redirected to file
stdout = output.txt

[tests]
; Note that we can omit definitions of text files

; This line describes files such as "1.in", "2.in", "3.in" and so on
in = text

; This line describes files "1.out", "2.out" ...
out = text
\endcode


\paragraph format_simple0_short_sample_par Short sample

\code{.ini}
[info]
name = Problem name
maintainers = admin

[resource_limits]
memory = 256MiB
time = 1

[files]
stdin = input.txt
stdout = output.txt
\endcode