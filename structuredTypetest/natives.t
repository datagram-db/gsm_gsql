native fixed int as int_fast32_t.
native fixed long as int_fast64_t.
native fixed short as int_fast8_t.
native fixed uint as uint_fast32_t.
native fixed ulong as uint_fast64_t.
native fixed ushort as uint_fast8_t.
native mutable vector as vector<@@>.
native mutable string as string.

access all fixed with arity "&!!context!!" by "&!!context!!" .
access string with arity "!!context!!.size()+1" by "!!context!!.c_data()" .
access vector with arity "!!context!!.size()" by  " " .