#ifndef __DIALOGADAPTER_H__
#define __DIALOGADAPTER_H__

#include "PageAdapter.h"




#define DIALOG_REGISTER_INFO \
	public: \
	static cocos2d::ObjectFactory::TInfo Type; \
	static cocos2d::Ref* createInstance(void); \

#define DIALOG_IMPLEMENT_INFO(name,className) \
	cocos2d::Ref* className::createInstance(void) \
		{ \
		return className::create(); \
		} \
		cocos2d::ObjectFactory::TInfo className::Type(name, &className::createInstance); \

#define CREATE_DIALOG_INFO(name,className) \
	cocos2d::ObjectFactory::TInfo(name, &className::createInstance)



class PageAdapter;
class DialogAdapter :public PageAdapter
{
public:
public:
	DialogAdapter();
	~DialogAdapter();

	static DialogAdapter* create(const std::string& filename);
	static DialogAdapter* create(Node* node);
	
	virtual void show();
	virtual void close() final;

	virtual void doShowAction();
	virtual void doCloseAction();

	virtual void behindScene();//����
	virtual void recoverScene();//�ָ�

	virtual DialogAdapter* setAutoClose(bool bAutoClose);
	virtual bool isAutoClose();

	virtual DialogAdapter* setStar(bool bStar);
	virtual bool isStar();


	virtual DialogAdapter* setListenBackKey(bool bListenBackKey);
	virtual bool isListenBackKey();

	virtual void setPreviousDialog(DialogAdapter* rPreviousDialog);
	virtual DialogAdapter* getPreviousDialog();

	virtual DialogAdapter* setMaskColor(const Color4F& color = Color4F(0, 0, 0, 0.6f));
	virtual Button* setBtnClickCallback(const std::string& path, const ccWidgetClickCallback& _clickCallBack);
	virtual Button* setCloseBtn(const std::string& path);

	virtual bool onKeyBack();

protected:
	virtual void initAdapter();

	bool _bIsAutoClose;
	bool _bStar;
	bool _bIsListenBackKey;
	
	DialogAdapter* _pPreviousDialog;
};


class DialogHelper
{
public:
	DialogHelper();
	~DialogHelper();
	
	static DialogAdapter* ShowUI(const std::string& filepath);
	static DialogAdapter* CloseUI(const std::string& filepath);
	static bool onKeyBack();
private:

};



#endif /* defined(__DIALOGADAPTER_H__) */
