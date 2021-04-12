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

static void		descriptionTemplate(t_template *template)
{
	if (!template)
	{
		description(template);
		return ;
	}

	printf("{ \"type\": \"template\"");

	// custome description code here..

	printf(" }");
}

void			setTemplate()
{
	if (!Class || classContainsInstance(Class, Template))
		return ;

	Template = Class->new();
	Template->new = (newType)newTemplate;
	Template->dealloc = (deallocType)deallocTemplate;
	Template->description = (descriptionType)descriptionTemplate;
}
