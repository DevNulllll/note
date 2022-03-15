switch(ch){
    case '\n':
        lines+=1;
    case ' ':
    case '\t':
        words+=1;
    default:
        chars+=1;
}
//换行符行数加一，单词数加一，空格和制表单词数加一，三者均增加一个字符
