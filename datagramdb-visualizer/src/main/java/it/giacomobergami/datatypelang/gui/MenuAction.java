package it.giacomobergami.datatypelang.gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.beans.PropertyChangeListener;

/**
 * Created by vasistas on 18/12/16.
 */
public abstract class MenuAction extends AbstractAction {
    public MenuAction(String elem) {
        super(elem);
    }
}
