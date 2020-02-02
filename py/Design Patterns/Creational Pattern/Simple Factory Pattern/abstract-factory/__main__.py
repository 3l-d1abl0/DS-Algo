from factory import GtkUIFactory, QtUIFactory

if __name__ == "__main__":
   gnome = True
   kde = not gnome

   if gnome:
      ui = GtkUIFactory()
   elif kde:
      ui = QtUIFactory()

   toolbox = ui.getToolboxWindow()
   layers = ui.getLayersWindow()
   main = ui.getMainWindow()

   print "%s:%s" % (toolbox.getToolkit(), toolbox.getType())
   print "%s:%s" % (layers.getToolkit(), layers.getType())
   print "%s:%s" % (main.getToolkit(), main.getType())


'''
https://premaseem.wordpress.com/2014/09/02/whats-the-difference-between-a-simple-factory-a-factory-method-design-pattern-and-an-abstract-factory/
https://www.tutorialspoint.com/python_design_patterns/python_design_patterns_abstract_factory.htm
'''
