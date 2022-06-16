## c++里面类型转换操作使用及区别 



### static_cast

> for casts that are checked at compile time only. **`static_cast`** returns an error if the compiler detects that you are trying to cast between types that are completely incompatible. You can also use it to cast between pointer-to-base and pointer-to-derived, but the compiler can't always tell whether such conversions will be safe at runtime.
##### syntax

```
static_cast <type-id> ( expression )
```

Converts an *expression* to the type of *type-id,* based only on the types that are present in the expression.

##### 备注：

标准C++里面 static_cast 不进行运行时检查，C++/CX有

static_cast可以被用来把基类指针转换为子类指针，但这样转换不总是安全的。



 ### dynamic_cast

 ### const_cast

### reinterpret_cast

