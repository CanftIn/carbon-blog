# carbon-blog

本项目旨在作为[Carbon](https://github.com/carbon-language/carbon-lang)语言的编译器实现和语言设计方面的指引。

计划内容涵盖：

- 如何一步一步实现现代编译器的前端（参照Carbon，目前我复刻的一个完整项目实现可参考：[Cocktail-lang](https://github.com/CanftIn/cocktail-lang)）
- 设计一门语言的思想（可能涉及诸如Rust/Swift/Haskell/Lisp等编程语言）

**内容补充中：**

- [X] [Chapter0: 项目介绍及构建](/blog/chapter0/project_structure/项目介绍及构建.md)
- [ ] [Chapter1: 数值字面量](/blog/chapter1/numeric_literal/数值字面量.md)
  - [ ] [section1: 数值字面量词法分析](/blog/chapter1/numeric_literal/section1_数值字面量词法分析.md)
  - [ ] [section2: 数值字面量语法解析](/blog/chapter1/numeric_literal/section2_数值字面量语法解析.md)
- [ ] [Chapter2: 诊断信息](/blog/chapter2/diagnostic/诊断信息.md)
  - [ ] [section1: 数值字面量接入诊断信息](/blog/chapter2/diagnostic/section1_数值字面量接入诊断信息.md)
- [ ] [Chapter3: 源码缓存](/blog/chapter3/source_buffer/源码缓存.md)
- [ ] [Chapter4: X-Macro](/blog/chapter4/X-Macro/X-Macro.md)
- [ ] [Chapter5: 符号缓存](/blog/chapter5/tokenized_buffer/符号缓存.md)
  - [ ] [section1: 基础定义](/blog/chapter5/tokenized_buffer/section1_基础定义.md)
  - [ ] [section2: Token Lexer词法分析](/blog/chapter5/tokenized_buffer/section2_Token_Lexer词法分析.md)
- [ ] [Chapter6: 单元测试及模糊测试](/blog/chapter6/单元测试及模糊测试介绍.md)
  - [ ] [section1: 对TokenizedBuffer进行单元测试](/blog/chapter6/unittest/对TokenizedBuffer进行单元测试.md)
  - [ ] [section2: 模糊测试](/blog/chapter6/fuzzing/模糊测试.md)
- [ ] [Chapter7: 语法分析](/blog/chapter7/parser/语法分析.md)
  - [ ] [section1: 语法节点类型定义](/blog/chapter7/parser/section1_语法节点类型定义.md)
  - [ ] [section2: 语法树定义](/blog/chapter7/parser/section2_语法树定义.md)
  - [ ] [section3: 语法树实现](/blog/chapter7/parsre/section3_语法树实现.md)
- [ ] [Chapter8: 基础组件实现](/blog/chapter8/common_tools/基础组件实现.md)
- [ ] [Chapter9: 编译器驱动](/blog/chapter9/driver/编译器驱动实现.md)
- [ ] [Chapter10: 语义分析](/blog/chapter10/sema/语义分析.md)
- [ ] [Chapter11: 验证型编译器](/blog/chatper11/experimental/验证型编译器.md)
  - [ ] [section1: flex](/blog/chapter11/experimental/section1_flex.md)
  - [ ] [section2: bison](/blog/chapter11/experimental/section2_bison.md)
  - [ ] [section3: interpreter](/blog/chapter11/experimental/section3_interpreter.md)
- [ ] [Chapter12: LLVM基础](/blog/chapter12/llvm/LLVM基础.md)
  - [ ] [section1: LLVM ADT介绍及使用](/blog/chapter12/llvm/section1_LLVM_ADT介绍及使用.md)
  - [ ] [section2: LLVM Support介绍及使用](/blog/chapter12/llvm/section2_LLVM_Support介绍及使用.md)

# License

本文所有文章受[Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License](https://creativecommons.org/licenses/by-nc-nd/4.0/)协议所保护。