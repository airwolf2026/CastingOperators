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

*static_cast* 和*dynamic_cast*都能够把类指针，在类层级里进行转换，不同的是，*dynamic_cast*遇到不能转换的时候，返回空，而*static_cast*需要程序猿保证转换后的结果是正确的

*static_cast* 能够被用来进行常用类型转换，以及用户自定义类型的隐式转换

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

*static_cast* 能够把整形转换到对应的枚举里，如果该整形不在该枚举里定义，则结果是未知的。

*static_cast*可以把空指针转换成目标类型的**空指针**。

任何类型都可以用*static_cast*显式的转换成**void 类型**，该void类型可以被**const**，**volatile**，或**__unaligned**修饰，但是反过来却不能去除这些修饰属性。

**<u>在性能很重要而且你能保证转换后的结果正确，可以考虑用static_cast进行转换</u>**

在C++/CLI 中可以用[safe_cast](https://docs.microsoft.com/en-us/cpp/extensions/safe-cast-cpp-component-extensions?view=msvc-170) 在debug模式下替换static_cast

 ### dynamic_cast

>for safe, runtime-checked casts of pointer-to-base to pointer-to-derived. A **`dynamic_cast`** is safer than a **`static_cast`** for downcasts, but the runtime check incurs some overhead.
>
>主要用来upcast 向上转换

##### syntax

```
dynamic_cast < type-id > ( expression )
```

##### 备注：

这里的**type-id** 一定要是指针或者某个类型的引用，甚或是void*指针。

**expression**当**type-id**是指针的时候，也要是指针，引用同理。

向上转换**upcast**，默认都是安全的，类似隐式转换

向下转换**downcast**，并不总是成功的，因为父类不知道子类的一些特性。

多重继承的情况下，把模棱两可的问题解决，就可以顺利的在整个继承链里面转换。

两个完全没关系的类型之间用**dynamic_cast**结果就是失败

### const_cast

>for casting away the const-ness of a variable, or converting a non-const variable to be const

**const_cast**用来把带**const**修饰的变量转换为没有**const**修饰，或反过来也行。

##### syntax

```
const_cast <type-id> (expression)
```

##### 备注：

const_cast 可以作用于指针或引用，可用于变量或者类成员。

You cannot use the **`const_cast`** operator to directly override a constant variable's constant status.

请不要用**const_cast**直接重写一个**const**变量的**const**状态

**const_cast** 作用域只在它出现的地方（The cast lasts only for the remainder of the statement in which it appears.）

```c++
const_cast< CCTest * >( this )->number--;
```



### reinterpret_cast

##### syntax

##### 备注：

### safe_cast

Used in C++/CLI to produce verifiable MSIL.

