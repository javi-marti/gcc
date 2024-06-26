// { dg-do compile { target c++11 } }

#define SA(X) static_assert((X),#X)

class ClassType { };

SA(__is_same(__add_rvalue_reference(int), int&&));
SA(__is_same(__add_rvalue_reference(int&&), int&&));
SA(__is_same(__add_rvalue_reference(int&), int&));
SA(__is_same(__add_rvalue_reference(const int), const int&&));
SA(__is_same(__add_rvalue_reference(int*), int*&&));
SA(__is_same(__add_rvalue_reference(ClassType&&), ClassType&&));
SA(__is_same(__add_rvalue_reference(ClassType), ClassType&&));
SA(__is_same(__add_rvalue_reference(int(int)), int(&&)(int)));
SA(__is_same(__add_rvalue_reference(void), void));
SA(__is_same(__add_rvalue_reference(const void), const void));
SA(__is_same(__add_rvalue_reference(bool(int) const), bool(int) const));
SA(__is_same(__add_rvalue_reference(bool(int) &), bool(int) &));
SA(__is_same(__add_rvalue_reference(bool(int) const &&), bool(int) const &&));
SA(__is_same(__add_rvalue_reference(bool(int)), bool(&&)(int)));
