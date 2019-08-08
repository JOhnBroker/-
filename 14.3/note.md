#### 第14张小结

0. 包含、虚继承、纯虚函数（抽象类）、MI、模板的使用（主要是（大部分编译器）模板不支持分离实现）

1. 段错误

   原因：访问的内存超过了系统所给这个程序的内存空间

   0. 访问类型错误：修改常量

   1. 访问了不属于进程地址空间的内存：把地址改成系统保护的内存地址`int *p; p=0;`

   2. 访问不存在的内存：`int *p=NULL; *p=1;`

   3. 内存越界，数据越界，**变量类型不一致**：将`const string变量复制到char* 变量中，然后会导致出错` 

   4. 类c语言，试图把一个整型按字符串的方式输出

      ```c
      int pos =0 ,cnt_printed_chars =0 ,i ;
      　　unsigned char *chptr ;
      　　va_list ap ;
      //...
      case 's':
      　　    chptr =va_arg (ap ,unsigned char *);
      　　    i =0 ;
      　　    while (chptr [i ])				//《-----
      　　    {...
      　　        cnt_printed_chars ++;
      　　        putchar (chptr [i ++]);
      　　}
      ```

   5. 栈溢出

   [一篇谈及到怎样定位错误的不错博客](https://blog.csdn.net/AAA123524457/article/details/80048072)

2. 私有继承
   访问基类方法： 使用作用域解析运算符来调用父类的公有方法``父类名称::公有方法``（只能在派生类中使用）
                             还可以用using声明，来指出派生类可以使用的基类成员 `using 类名::成员名`
                           （声明中只使用成员名<!--不包括圆括号 函数特征标 返回类型-->）
                           （除了基类的私有成员是不可以这样声明）
   访问基类对象：用强制类型转换`(父类 &)(*this)`<!--转成基类的引用-->
   访问基类的友元函数：通过显式类型转换为基类来调用正确的函数（友元不属于类）

3. 调用了纯虚函数会怎么样，但是尽量不要调用它
   关于当基类构析函数为纯虚函数时，因为基类对象是会被先构造的，（抽象类是不能实例化对象），然后基类对象后构析，还是无法避免的调用到纯虚函数。

4. 模板类的一些注意事项

   0. 类型参数、非类型、表达式参数

      1. 类型参数`class Type / typename Type`
      2. 非类型参数
         可以是整型、枚举、引用/指针。**用作表达式参数的值必须是常量表达式**

   1.  模板类

      显式具体化：`template <> class Classname<specialized-type-name>{}` <!--<>中声明的是没被具体化的参数-->
      显式实例化：`template class Classname<specialized-type-name> object-name;`
      隐式实例化：`Classname<specialized-type-name> object-name`
      在模板类A中嵌套一个模板类B，但在模板A外定义模板B的方法时`template <typename TA>\n \t template<typename TB> \n \t\t Classname:Functionname`
      将模板用作参数：`template <tempplate T>class parameter`,` template <tempplate T>class`是类型
      模板友元：
      		约束型:`template <typename T>void FuntionName()//delare`
      			  `template<typename TT>class{friend void FunctionName<TT>(); }...//声明具体化`
      			  `template<typename T>\n void FunctionName(){...}//方法具体化`
      		非约束：在类内部声明模板`template<...>class ClassName{template<...>friend returnType FunctionName(ParameterName);}`

   2. 模板函数
      可以省略实参，但是有时候要注意类型问题

      ```c++
      //declare & realization
      template<class T>
      T Classname::test(T a,T b){
      	return a*a+b*b;
      }
      //example
      test(2,4);//ok
      test(2,2.6);//error 
      //疑问：为什么2.6不能强转为int类型，然后截断2.6呢？
      ```
      
   3. **大部分编译器是不支持模板的分离实现的**

