<?php
/**
 * @file
 * Custom panels full-width wrappers.
 */

// Plugin registration
$plugin = array(
  'title' => t('Full width wrapper'),
  'description' => t('Set a full page wrapper on this content.'),
  'render pane' => 'as_wrapper_style_render_pane',
  'render region' => 'as_wrapper_style_render_region',
  'settings form' => 'as_wrapper_settings_form',
  'pane settings form' => 'as_wrapper_settings_form',
  'category' => t('Accordance Systems'),
  'hook theme'    => array(
    'wrapper_region' => array(
      'template' => 'wrapper-region',
       'path' => drupal_get_path('theme', 'accordancesystems') .'/panels/styles',
       'variables' => array(
         'content' => NULL,
         'settings' => NULL,
       ),
      ),
  ),
);

/**
 * Renders the pane content.
 */
function theme_as_wrapper_style_render_pane($content) {
  if (!empty($content)) {
    return theme('panels_pane', $content);
  }
}

/**
 * Renders the region.
 */
function theme_as_wrapper_style_render_region($variables) {
  if (!empty($variables)) {
    $content = '';

  foreach ($variables['panes'] as $pane_id => $pane_output) {

    $content .= $pane_output;
  }
  if (empty($content)) {
    return;
  }
  return theme('wrapper_region',
    array(
      'content' => $content,
      'settings' => $variables['settings'],
      'style' => $variables['style'],
    ));
  }
}
