#ifndef VISUAL_SCRIPT_NODES_H
#define VISUAL_SCRIPT_NODES_H

#include "visual_script.h"

class VisualScriptFunction : public VisualScriptNode {

	OBJ_TYPE(VisualScriptFunction,VisualScriptNode)


	struct Argument {
		String name;
		Variant::Type type;
	};

	Vector<Argument> arguments;

	bool stack_less;
	int stack_size;
	ScriptInstance::RPCMode rpc_mode;


protected:

	bool _set(const StringName& p_name, const Variant& p_value);
	bool _get(const StringName& p_name,Variant &r_ret) const;
	void _get_property_list( List<PropertyInfo> *p_list) const;

public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "flow_control"; }

	void add_argument(Variant::Type p_type,const String& p_name,int p_index=-1);
	void set_argument_type(int p_argidx,Variant::Type p_type);
	Variant::Type get_argument_type(int p_argidx) const;
	void set_argument_name(int p_argidx,const String& p_name);
	String get_argument_name(int p_argidx) const;
	void remove_argument(int p_argidx);
	int get_argument_count() const;


	void set_stack_less(bool p_enable);
	bool is_stack_less() const;

	void set_stack_size(int p_size);
	int get_stack_size() const;

	void set_rpc_mode(ScriptInstance::RPCMode p_mode);
	ScriptInstance::RPCMode get_rpc_mode() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptFunction();
};


class VisualScriptOperator : public VisualScriptNode {

	OBJ_TYPE(VisualScriptOperator,VisualScriptNode)


	Variant::Type typed;
	Variant::Operator op;
protected:

	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "operators"; }

	void set_operator(Variant::Operator p_op);
	Variant::Operator get_operator() const;

	void set_typed(Variant::Type p_op);
	Variant::Type get_typed() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptOperator();
};


class VisualScriptVariableGet : public VisualScriptNode {

	OBJ_TYPE(VisualScriptVariableGet,VisualScriptNode)


	StringName variable;
protected:

	virtual void _validate_property(PropertyInfo& property) const;
	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_variable(StringName p_var);
	StringName get_variable() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptVariableGet();
};


class VisualScriptVariableSet : public VisualScriptNode {

	OBJ_TYPE(VisualScriptVariableSet,VisualScriptNode)


	StringName variable;
protected:

	virtual void _validate_property(PropertyInfo& property) const;
	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_variable(StringName p_var);
	StringName get_variable() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptVariableSet();
};


class VisualScriptConstant : public VisualScriptNode {

	OBJ_TYPE(VisualScriptConstant,VisualScriptNode)


	Variant::Type type;
	Variant value;
protected:
	virtual void _validate_property(PropertyInfo& property) const;
	static void _bind_methods();

public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_constant_type(Variant::Type p_type);
	Variant::Type get_constant_type() const;

	void set_constant_value(Variant p_value);
	Variant get_constant_value() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptConstant();
};



class VisualScriptPreload : public VisualScriptNode {

	OBJ_TYPE(VisualScriptPreload,VisualScriptNode)


	Ref<Resource> preload;
protected:

	static void _bind_methods();

public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_preload(const Ref<Resource>& p_value);
	Ref<Resource> get_preload() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptPreload();
};

class VisualScriptIndexGet : public VisualScriptNode {

	OBJ_TYPE(VisualScriptIndexGet,VisualScriptNode)


public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "operators"; }

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptIndexGet();
};


class VisualScriptIndexSet : public VisualScriptNode {

	OBJ_TYPE(VisualScriptIndexSet,VisualScriptNode)


public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "operators"; }

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptIndexSet();
};



class VisualScriptGlobalConstant : public VisualScriptNode {

	OBJ_TYPE(VisualScriptGlobalConstant,VisualScriptNode)

	int index;

	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_global_constant(int p_which);
	int get_global_constant();

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptGlobalConstant();
};



class VisualScriptMathConstant : public VisualScriptNode {

	OBJ_TYPE(VisualScriptMathConstant,VisualScriptNode)
public:

	enum MathConstant {
		MATH_CONSTANT_ONE,
		MATH_CONSTANT_PI,
		MATH_CONSTANT_2PI,
		MATH_CONSTANT_HALF_PI,
		MATH_CONSTANT_E,
		MATH_CONSTANT_SQRT2,
		MATH_CONSTANT_MAX,
	};

private:
	static const char* const_name[MATH_CONSTANT_MAX];
	static double const_value[MATH_CONSTANT_MAX];
	MathConstant constant;
protected:
	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_math_constant(MathConstant p_which);
	MathConstant get_math_constant();

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptMathConstant();
};

VARIANT_ENUM_CAST( VisualScriptMathConstant::MathConstant )

class VisualScriptEngineSingleton : public VisualScriptNode {

	OBJ_TYPE(VisualScriptEngineSingleton,VisualScriptNode)

	String singleton;

	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_singleton(const String &p_string);
	String get_singleton();

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptEngineSingleton();
};




class VisualScriptSceneNode : public VisualScriptNode {

	OBJ_TYPE(VisualScriptSceneNode,VisualScriptNode)

	NodePath path;
protected:
	virtual void _validate_property(PropertyInfo& property) const;
	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_node_path(const NodePath &p_path);
	NodePath get_node_path();

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptSceneNode();
};




class VisualScriptSceneTree : public VisualScriptNode {

	OBJ_TYPE(VisualScriptSceneTree,VisualScriptNode)


protected:
	virtual void _validate_property(PropertyInfo& property) const;
	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptSceneTree();
};



class VisualScriptResourcePath : public VisualScriptNode {

	OBJ_TYPE(VisualScriptResourcePath,VisualScriptNode)

	String path;
protected:

	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }

	void set_resource_path(const String &p_path);
	String get_resource_path();

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptResourcePath();
};


class VisualScriptSelf : public VisualScriptNode {

	OBJ_TYPE(VisualScriptSelf,VisualScriptNode)


protected:

	static void _bind_methods();
public:

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const { return "data"; }


	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptSelf();
};


class VisualScriptCustomNode: public VisualScriptNode {

	OBJ_TYPE(VisualScriptCustomNode,VisualScriptNode)


protected:

	virtual bool _use_builtin_script() const { return true; }

	static void _bind_methods();
public:

	enum StartMode { //replicated for step
		START_MODE_BEGIN_SEQUENCE,
		START_MODE_CONTINUE_SEQUENCE,
		START_MODE_RESUME_YIELD
	};

	enum { //replicated for step
		STEP_SHIFT=1<<24,
		STEP_MASK=STEP_SHIFT-1,
		STEP_PUSH_STACK_BIT=STEP_SHIFT, //push bit to stack
		STEP_GO_BACK_BIT=STEP_SHIFT<<1, //go back to previous node
		STEP_NO_ADVANCE_BIT=STEP_SHIFT<<2, //do not advance past this node
		STEP_EXIT_FUNCTION_BIT=STEP_SHIFT<<3, //return from function
		STEP_YIELD_BIT=STEP_SHIFT<<4, //yield (will find VisualScriptFunctionState state in first working memory)
	};

	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptCustomNode();
};

class VisualScriptSubCall: public VisualScriptNode {

	OBJ_TYPE(VisualScriptSubCall,VisualScriptNode)


protected:


	static void _bind_methods();
public:
	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptSubCall();
};

class VisualScriptComment: public VisualScriptNode {

	OBJ_TYPE(VisualScriptComment,VisualScriptNode)


	String title;
	String description;
	Size2 size;
protected:

	static void _bind_methods();
public:
	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	void set_title(const String& p_title);
	String get_title() const;

	void set_description(const String& p_description);
	String get_description() const;

	void set_size(const Size2& p_size);
	Size2 get_size() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptComment();
};

class VisualScriptConstructor: public VisualScriptNode {

	OBJ_TYPE(VisualScriptConstructor,VisualScriptNode)


	Variant::Type type;
	MethodInfo constructor;

protected:


	static void _bind_methods();
public:
	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	void set_constructor_type(Variant::Type p_type);
	Variant::Type get_constructor_type() const;

	void set_constructor(const Dictionary& p_info);
	Dictionary get_constructor() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptConstructor();
};




class VisualScriptLocalVar: public VisualScriptNode {

	OBJ_TYPE(VisualScriptLocalVar,VisualScriptNode)

	StringName name;
	Variant::Type type;

protected:

	static void _bind_methods();
public:
	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	void set_var_name(const StringName& p_name);
	StringName get_var_name() const;

	void set_var_type(Variant::Type p_type);
	Variant::Type get_var_type() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptLocalVar();
};




class VisualScriptInputAction: public VisualScriptNode {

	OBJ_TYPE(VisualScriptInputAction,VisualScriptNode)

	StringName name;

protected:

	virtual void _validate_property(PropertyInfo& property) const;

	static void _bind_methods();
public:
	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	void set_action_name(const StringName& p_name);
	StringName get_action_name() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptInputAction();
};



class VisualScriptDeconstruct: public VisualScriptNode {

	OBJ_TYPE(VisualScriptDeconstruct,VisualScriptNode)


	struct Element {
		StringName name;
		Variant::Type type;
	};


	Vector<Element> elements;

	void _update_elements();
	Variant::Type type;
	InputEvent::Type input_type;

	void _set_elem_cache(const Array& p_elements);
	Array _get_elem_cache() const;

	virtual void _validate_property(PropertyInfo& property) const;

protected:


	static void _bind_methods();
public:
	virtual int get_output_sequence_port_count() const;
	virtual bool has_input_sequence_port() const;


	virtual String get_output_sequence_port_text(int p_port) const;


	virtual int get_input_value_port_count() const;
	virtual int get_output_value_port_count() const;


	virtual PropertyInfo get_input_value_port_info(int p_idx) const;
	virtual PropertyInfo get_output_value_port_info(int p_idx) const;

	virtual String get_caption() const;
	virtual String get_text() const;
	virtual String get_category() const;

	void set_deconstruct_type(Variant::Type p_type);
	Variant::Type get_deconstruct_type() const;

	void set_deconstruct_input_type(InputEvent::Type p_input_type);
	InputEvent::Type get_deconstruct_input_type() const;

	virtual VisualScriptNodeInstance* instance(VisualScriptInstance* p_instance);

	VisualScriptDeconstruct();
};


void register_visual_script_nodes();
void unregister_visual_script_nodes();

#endif // VISUAL_SCRIPT_NODES_H
