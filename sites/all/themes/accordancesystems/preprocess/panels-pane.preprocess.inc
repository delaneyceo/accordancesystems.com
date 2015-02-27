<?php
/**
 * @file
 * Preprocess panels color preset and theme hook suggestions.
 */

/**
 * Implements hook_preprocess_panels_pane().
 */
function accordancesystems_preprocess_panels_pane(&$variables) {

  if(isset($variables['pane']->style['style'])) {
    // Wrapper style.
    if($variables['pane']->style['style'] === 'wrapper') {
      $variables['theme_hook_suggestions'][] = 'panels_pane__wrapper';
      $variables['attributes_array']['class'][] = $variables['pane']->style['settings']['preset_color'];
    }
  }

  // Add a class to the panel pane for the view mode if we are rendering a node.
  if(isset($variables['content']['#entity_type']) && $variables['content']['#entity_type'] == 'node') {
    $variables['classes_array'][] = 'view-mode-' . $variables['content']['#view_mode'];
  }

  return $variables;
}
