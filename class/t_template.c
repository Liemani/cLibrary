#include <stdio.h>
#include <stdlib.h>

#include "t_template.h"
#include "class.h"



static t_template	*_newTemplate()
{
	t_template	*template;

	lmtAlloc(template);
	classAddInstance(Template, template);
	
	// custome new code here..

	return (template);
}

static void		_deallocTemplate(t_template *template)
{
	if (!template)
		return ;

	classRemoveInstance(Template, template);

	// custome dealloc code here..

	free(template);
}

static void		_descriptionTemplate(t_template *template)
{
	if (!template)
	{
		description(template);
		return ;
	}

	printf("t_template: [ ");

	// custome description code here..

	printf(" ]");
}

void			setTemplate()
{
	if (!Class || classContainsInstance(Class, Template))
		return ;

	Template = Class->new();
	Template->new = (newType)_newTemplate;
	Template->dealloc = (deallocType)_deallocTemplate;
	Template->description = (descriptionType)_descriptionTemplate;
}
