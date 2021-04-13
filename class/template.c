#include <stdio.h>
#include <stdlib.h>

#include "template.h"
#include "class.h"



static t_template	*newTemplate()
{
	t_template	*template;

	lmtAlloc(template);
	classAddInstance(Template, template);
	
	// custome new code here..

	return (template);
}

static void		deallocTemplate(t_template *template)
{
	if (!template)
		return ;

	classRemoveInstance(Template, template);

	// custome dealloc code here..

	free(template);
}

static t_string	*descriptionTemplate(t_template *template)
{
	t_string	*string;

	string = String->new();
	if (!template)
	{
		stringMergeString(string, description(template));
		return (string);
	}

	stringAppendStr(string, "{ \"type\": \"template\"");

	// custome description code here..

	stringAppendStr(string, " }");

	return (string);
}

void			setTemplateClass()
{
	if (!Class || classContainsInstance(Class, Template))
		return ;

	Template = Class->new();
	Template->new = (newType)newTemplate;
	Template->dealloc = (deallocType)deallocTemplate;
	Template->description = (descriptionType)descriptionTemplate;
}
