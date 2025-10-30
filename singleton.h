#ifndef SINGLETON_H
#define SINGLETON_H
#include"global.h"
#include "qdebug.h"
#include "qglobal.h"
#include <memory>
#include <mutex>
//利用奇异递归模板实现单例模板
//懒汉式
using namespace std;
template<typename T>//单例类模板，实现类只有一个实例
class Singleton{
    protected:
     Singleton() = default;//在protected中，实现私有构造
        Singleton(const Singleton<T>&)= delete;//删除拷贝与赋值防止创建新实例
      Singleton& operator=(const Singleton<T>& st) = delete;
        static shared_ptr<T> _instance;//饿汉，利用静态局部变量保证线程安全
      //且使用shared_ptr智能指针动态管理此对象
    public:
        static std::shared_ptr<T> GetInstance()// // 静态方法获取唯一实例
        {
            static std::once_flag s_flag;//once_flag确保初始化代码只执行一次的标志
            //call_once保证传入的lambda函数只会被执行一次
            //lambda作闭包用
            std::call_once(s_flag, [&](){
                _instance = shared_ptr<T>(new T);
                //初始化唯一实例_instance，其被智能指针管理
            });

            return _instance;
        }
        void PrintAddress() {
            qDebug()<<_instance.get();//打印单例对象的内存地址
        }
        ~Singleton() {
            qDebug()<< u8"单例destruct" ;
            //用于在单例对象被销毁时输出一条消息。
        }
};
//模板成员函数和静态成员变量必须在类模板外进行定义
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;
#endif // SINGLETON_H
