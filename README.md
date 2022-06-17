## c++里面类型转换操作使用及区别 



### static_cast

> for casts that are checked at compile time only. **`static_cast`** returns an error if the compiler detects that you are trying to cast between types that are completely incompatible. You can also use it to cast between pointer-to-base and pointer-to-derived, but the compiler can't always tell whether such conversions will be safe at runtime.
##### syntax

```
static_cast <type-id> ( expression )
```

Converts an *expression* to the type of *type-id,* based only on the types that are present in the expression.

##### 备注：

标准C++里面 *static_cast* 不进行运行时检查，C++/CX有

*static_cast*可以被用来把基类指针转换为子类指针，但这样转换不总是安全的。

*static_cast*常常被用来进行数值类型的转换：枚举-ints 或ints-floats等

当不能准确转换的时候，由于*static_cast*没有进行运行时检查，*static_cast* 仍然正常返回，就像没有错误发生一样，而*dynamic_cast*在遇到不能转换的时候，会返回错误（空）

*static_cast* 和*dynamic_cast*都能够把类指针，在类层级里进行转换，不同的是，*dynamic_cast*遇到不能转换的时候，返回空，而*statci_cast*需要程序猿保证转换后的结果是正确的

*statci_cast* 能够被用来进行常用类型转换，以及用户自定义类型的隐式转换

```
typedef unsigned char BYTE;

void f() {
   char ch;
   int i = 65;
   float f = 2.5;
   double dbl;

   ch = static_cast<char>(i);   // int to char
   dbl = static_cast<double>(f);   // float to double
   i = static_cast<BYTE>(ch);
}
```

*statc_cast* 能够把整形转换到对应的枚举里，如果该整形不在该枚举里定义，则结果是未知的。

*static_cast*可以把空指针转换成目标类型的**空指针**。

任何类型都可以用*statci_cast*显式的转换成**void 类型**，该void类型可以被**const**，**volatile**，或**__unaligned**修饰，但是反过来却不能去除这些修饰属性。

**<u>在性能很重要而且你能保证转换后的结果正确，可以考虑用statci_cast进行转换</u>**

 ### dynamic_cast

 ### const_cast

### reinterpret_cast

